// Capture support for WinRT
// Microsoft Surface and Phone using Media Foundation

// Copyright (c) 2013, Microsoft Open Technologies, Inc. 
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

#include "precomp.hpp"

//#include <collection.h>
//#include <ppltasks.h>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <atomic>

#include <agile.h>

// #include "cap_winrt/CaptureFrameGrabber.h"

// implement the newer IVideoCapture so that we can work
// directly with Mat, not the cv interface which has added overhead

namespace cv {

    class VideoCapture_WinRT : public IVideoCapture
    {
    public:
        VideoCapture_WinRT() :
            started(false)
            //bytesPerPixel(0),
            //frameCounter(0),
            //frameCurrent(0),
        {}

        VideoCapture_WinRT(int device);

        virtual ~VideoCapture_WinRT()
        {
            // close();
        }

        // from base class IVideoCapture
        virtual double getProperty(int) { return 0; }
        virtual bool setProperty(int, double);
        virtual bool grabFrame();
        virtual bool retrieveFrame(int channel, cv::OutputArray outArray);

        // Return the type of the capture object
        virtual int getCaptureDomain() { return CAP_WINRT; }

        // std::vector<std::string> listDevices();

        void start();

        Mat frontInputMat;
        Mat backInputMat;

    protected:

        // cannot be in this class because we don't have an instance of Media::CaptureFrameGrabber^
        //void GrabFrameAsync(::Media::CaptureFrameGrabber^ frameGrabber);

        //Platform::Agile<::Windows::Media::Capture::MediaCapture> m_capture;
        //Platform::Agile<Windows::Devices::Enumeration::DeviceInformationCollection> m_devices;

        bool    started;

        CvSize                  size;
        int                     bytesPerPixel;
        unsigned long           frameCurrent;
        std::atomic<bool>       isFrameNew;
    };
}