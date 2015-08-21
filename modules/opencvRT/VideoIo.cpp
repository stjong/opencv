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

#include "pch.h"

#include "../src/cap_winrt_highgui.hpp"
#include "VideoIo.h"

// nb. path relative to modules/videoio/include

using namespace ::concurrency;
using namespace ::Windows::Foundation;
using namespace ::Windows::UI::Xaml::Controls;
// using namespace cv;
using namespace cvRT;

VideoIo::VideoIo()
{
}

void VideoIo::Initialize()
{
	auto asyncTask = create_async([this](progress_reporter<int> reporter)
						{
							HighguiBridge::getInstance().setReporter(reporter);
						});

	asyncTask->Progress = ref new AsyncActionProgressHandler<int>([this](IAsyncActionWithProgress<int>^ act, int progress)
	{
		int action = progress;

		// these actions will be processed on the UI thread asynchronously
		switch (action)
		{
		case OPEN_CAMERA:
		{
			int device = HighguiBridge::getInstance().deviceIndex;
			int width = HighguiBridge::getInstance().width;
			int height = HighguiBridge::getInstance().height;

			// buffers must alloc'd on UI thread
			allocateBuffers(width, height);

			// nb. video capture device init must be done on UI thread;
			// code is located in the OpenCV Highgui DLL, class Video
			if (!grabberStarted)
			{
				grabberStarted = true;
				initGrabber(device, width, height);
			}
		}
		break;
		case CLOSE_CAMERA:
			closeGrabber();
			break;
		case UPDATE_IMAGE_ELEMENT:
		{
			// copy output Mat to WBM
			copyOutput();

			// set XAML image element with image WBM
			HighguiBridge::getInstance().cvImage->Source = HighguiBridge::getInstance().backOutputBuffer;
		}
		break;

		//case SHOW_TRACKBAR:
		//    cvSlider->Visibility = Windows::UI::Xaml::Visibility::Visible;
		//    break;

		}
	});
}

void VideoIo::SetImage(Windows::UI::Xaml::Controls::Image^ cvImage)
{
	HighguiBridge::getInstance().cvImage = cvImage;
}

void VideoIo::StartCapture()
{
	vidCap.open(0);
}


void VideoIo::StopCapture()
{
	vidCap.release();
}

void VideoIo::GetFrame(Mat^ frame)
{
	// tbd can't loop forever here.
	while (1)
	{
		vidCap >> frame->Get();

		// tbd these are from original sample.  need to look more into this.
		if (!vidCap.grab())
			continue;

		// ditto as above.
		if (frame->Get().total() == 0)
			continue;

		break;
	}

	OutputDebugString(L"Frame obtained");
}

void VideoIo::ShowFrame(Mat^ frame)
{
	imshow_winrt(frame->Get());
}