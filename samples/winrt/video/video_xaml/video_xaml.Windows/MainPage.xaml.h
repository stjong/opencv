﻿//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace Media
{
    ref class CaptureFrameGrabber;
}

namespace video_xaml
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
    protected:
        Windows::Foundation::IAsyncActionWithProgress<int>^ TaskWithProgressAsync();
    };
}