//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include <opencv2\core\core.hpp>

namespace AppUap2
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
	private:
		cv::Mat Lena;
		void UpdateImage(const cv::Mat& image);
	private:
		void btn1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn1_Copy_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn1_Copy1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
