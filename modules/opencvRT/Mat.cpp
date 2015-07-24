#include "pch.h"

using namespace cvRT;

Mat::Mat()
{
	_rawMatHolder = new cv::Mat();
}

Mat::Mat(cv::Mat& rawMat)
{
	_rawMatHolder = &rawMat;
}

unsigned int Mat::total()
{
    return _rawMatHolder->total();
}
