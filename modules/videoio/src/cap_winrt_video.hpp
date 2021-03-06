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

#pragma once

#include "cap_winrt/CaptureFrameGrabber.hpp"

#include <mutex>
#include <memory>

class Video {
public:

    bool initGrabber(int device, int w, int h);
    void closeGrabber();

    // singleton
    static Video &getInstance();

    void CopyOutput();

private:
    // singleton
    Video();

    void _GrabFrameAsync(::Media::CaptureFrameGrabber^ frameGrabber);

    bool listDevices();

    Platform::Agile<Windows::Media::Capture::MediaCapture> m_capture;
    Platform::Agile<Windows::Devices::Enumeration::DeviceInformationCollection> m_devices;

    ::Media::CaptureFrameGrabber^ m_frameGrabber;

    bool listDevicesTask();

    bool					bChooseDevice;
    bool 					bVerbose;
    bool                    bFlipImageX;
    std::atomic<bool>       bGrabberInited;
    int						m_deviceID;
    int						attemptFramerate;
    std::atomic<bool>       bIsFrameNew;
    unsigned int			width, height;
    int                     bytesPerPixel;

};