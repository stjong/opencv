#include "pch.h"


#include "Mat.h"
#include "HighGui.h"
#include "cap_winrt.hpp"
#include "cap_winrt_highgui.hpp"
#include "cap_winrt_video.hpp"

using namespace cvRT;

HighGui::HighGui()
{
}

void HighGui::imshow(cvRT::Mat^ img)
{
    imshow_winrt(img->RawMat());
}