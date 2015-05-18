// Video support with XAML
// Microsoft Surface and Phone using Media Foundation

// Copyright (c) 2015, Microsoft Open Technologies, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// - Neither the name of Microsoft Open Technologies, Inc. nor the names
//   of its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "cap_winrt_video.hpp"

#include <ppl.h>
#include <ppltasks.h>
#include <concrt.h>
#include <agile.h>

#include <atomic>
#include <future>
#include <vector>


using namespace ::concurrency;
using namespace ::Windows::Foundation;
using namespace ::std;

using namespace Microsoft::WRL;
using namespace Windows::Media::Devices;
using namespace Windows::Media::MediaProperties;
using namespace Windows::Media::Capture;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Devices::Enumeration;

#include "cap_winrt/CaptureFrameGrabber.hpp"

// pull in Media Foundation libs
#pragma comment(lib, "mfplat")
#pragma comment(lib, "mf")
#pragma comment(lib, "mfuuid")

#if (WINAPI_FAMILY!=WINAPI_FAMILY_PHONE_APP) && !defined(_M_ARM)
#pragma comment(lib, "Shlwapi")
#endif

#include "cap_winrt_highgui.hpp"

Video::Video() {}

Video &Video::getInstance() {
    static Video v;
    return v;
}

void Video::closeGrabber() {
    // assigning nullptr causes deref of grabber and thus closes the device
    m_frameGrabber = nullptr;
    bGrabberInited = false;
}


bool Video::initGrabber(int device, int w, int h) {
    // already started?
    if (bGrabberInited) return false;

    width = w;
    height = h;

    bGrabberInited = false;

    m_deviceID = device;

    create_task(DeviceInformation::FindAllAsync(DeviceClass::VideoCapture))
        .then([this](task<DeviceInformationCollection^> findTask)
    {
        m_devices = findTask.get();

        // got selected device?
        if ((unsigned)m_deviceID >= m_devices.Get()->Size)
        {
            OutputDebugStringA("Video::initGrabber - no video device found\n");
            return false;
        }

        auto devInfo = m_devices.Get()->GetAt(m_deviceID);

        auto settings = ref new MediaCaptureInitializationSettings();
        settings->StreamingCaptureMode = StreamingCaptureMode::Video; // Video-only capture
        settings->VideoDeviceId = devInfo->Id;

        auto location = devInfo->EnclosureLocation;
        bFlipImageX = true;
        if (location != nullptr && location->Panel == Windows::Devices::Enumeration::Panel::Back)
        {
            bFlipImageX = false;
        }

        m_capture = ref new MediaCapture();
        create_task(m_capture->InitializeAsync(settings)).then([this](){

            auto props = safe_cast<VideoEncodingProperties^>(m_capture->VideoDeviceController->GetMediaStreamProperties(MediaStreamType::VideoPreview));

            // for 24 bpp
            props->Subtype = MediaEncodingSubtypes::Rgb24;      bytesPerPixel = 3;

            // format used by XAML & WBM (for testing)
            // props->Subtype = MediaEncodingSubtypes::Bgra8;   bytesPerPixel = 4;

            props->Width = width;
            props->Height = height;

            return ::Media::CaptureFrameGrabber::CreateAsync(m_capture.Get(), props);

        }).then([this](::Media::CaptureFrameGrabber^ frameGrabber)
        {
            m_frameGrabber = frameGrabber;
            bGrabberInited = true;
            //ready = true;
            _GrabFrameAsync(frameGrabber);
        });

        return true;
    });

    // nb. cannot block here - this will lock the UI thread:

    return true;
}


void Video::_GrabFrameAsync(::Media::CaptureFrameGrabber^ frameGrabber) {
    // use rgb24 layout
    create_task(frameGrabber->GetFrameAsync()).then([this, frameGrabber](const ComPtr<IMF2DBuffer2>& buffer)
    {
        // do the RGB swizzle while copying the pixels from the IMF2DBuffer2
        BYTE *pbScanline;
        LONG plPitch;
        unsigned int colBytes = width * bytesPerPixel;
        CHK(buffer->Lock2D(&pbScanline, &plPitch));

        // flip
        if (bFlipImageX)
        {
            std::lock_guard<std::mutex> lock(HighguiBridge::getInstance().inputBufferMutex);

            // ptr to input Mat data array
            auto buf = HighguiBridge::getInstance().backInputPtr;

            for (unsigned int row = 0; row < height; row++)
            {
                unsigned int i = 0;
                unsigned int j = colBytes - 1;

                while (i < colBytes)
                {
                    // reverse the scan line
                    // as a side effect this also swizzles R and B channels
                    buf[j--] = pbScanline[i++];
                    buf[j--] = pbScanline[i++];
                    buf[j--] = pbScanline[i++];
                }
                pbScanline += plPitch;
                buf += colBytes;
            }
            HighguiBridge::getInstance().bIsFrameNew = true;
        } else
        {
            std::lock_guard<std::mutex> lock(HighguiBridge::getInstance().inputBufferMutex);

            // ptr to input Mat data array
            auto buf = HighguiBridge::getInstance().backInputPtr;

            for (unsigned int row = 0; row < height; row++)
            {
                // used for Bgr8:
                //for (unsigned int i = 0; i < colBytes; i++ )
                //    buf[i] = pbScanline[i];

                // used for RGB24:
                for (unsigned int i = 0; i < colBytes; i += bytesPerPixel)
                {
                    // swizzle the R and B values (BGR to RGB)
                    buf[i] = pbScanline[i + 2];
                    buf[i + 1] = pbScanline[i + 1];
                    buf[i + 2] = pbScanline[i];

                    // no swizzle
                    //buf[i] = pbScanline[i];
                    //buf[i + 1] = pbScanline[i + 1];
                    //buf[i + 2] = pbScanline[i + 2];
                }

                pbScanline += plPitch;
                buf += colBytes;
            }
            HighguiBridge::getInstance().bIsFrameNew = true;
        }
        CHK(buffer->Unlock2D());

        HighguiBridge::getInstance().frameCounter++;

        if (bGrabberInited)
        {
            _GrabFrameAsync(frameGrabber);
        }
    }, task_continuation_context::use_current());
}


// copy from input Mat to output WBM
// must be on UI thread
void Video::CopyOutput() {
    {
        std::lock_guard<std::mutex> lock(HighguiBridge::getInstance().outputBufferMutex);

        auto inAr = HighguiBridge::getInstance().frontInputPtr;
        auto outAr = GetData(HighguiBridge::getInstance().frontOutputBuffer->PixelBuffer);

        const unsigned int bytesPerPixel = 3;
        auto pbScanline = inAr;
        auto plPitch = width * bytesPerPixel;

        auto buf = outAr;
        unsigned int colBytes = width * 4;

        // copy RGB24 to bgra8
        for (unsigned int row = 0; row < height; row++)
        {
            // used for Bgr8:
            // nb. no alpha
            // for (unsigned int i = 0; i < colBytes; i++ ) buf[i] = pbScanline[i];

            // used for RGB24:
            // nb. alpha is set to full opaque
            for (unsigned int i = 0, j = 0; i < plPitch; i += bytesPerPixel, j += 4)
            {
                // swizzle the R and B values (RGB24 to Bgr8)
                buf[j] = pbScanline[i + 2];
                buf[j + 1] = pbScanline[i + 1];
                buf[j + 2] = pbScanline[i];
                buf[j + 3] = 0xff;

                // if no swizzle is desired:
                //buf[i] = pbScanline[i];
                //buf[i + 1] = pbScanline[i + 1];
                //buf[i + 2] = pbScanline[i + 2];
                //buf[i + 3] = 0xff;
            }

            pbScanline += plPitch;
            buf += colBytes;
        }
        HighguiBridge::getInstance().frontOutputBuffer->PixelBuffer->Length = width * height * 4;
    }
}


bool Video::listDevicesTask() {
    std::atomic<bool> ready(false);

    auto settings = ref new MediaCaptureInitializationSettings();

    //vector <int> devices;

    create_task(DeviceInformation::FindAllAsync(DeviceClass::VideoCapture))
        .then([this, &ready](task<DeviceInformationCollection^> findTask)
    {
        m_devices = findTask.get();

        for (size_t i = 0; i < m_devices->Size; i++)
        {
            // ofVideoDevice deviceInfo;
            auto d = m_devices->GetAt(i);
            //deviceInfo.bAvailable = true;
            //deviceInfo.deviceName = PlatformStringToString(d->Name);
            //deviceInfo.hardwareName = deviceInfo.deviceName;
            // devices.push_back(deviceInfo);
        }

        ready = true;
    });

    // wait for async task to complete
    int count = 0;
    while (!ready)
    {
        count++;
    }

    return true;
}


bool Video::listDevices() {
    // synchronous version of listing video devices on WinRT
    std::future<bool> result = std::async(std::launch::async, &Video::listDevicesTask, this);
    return result.get();
}

// end