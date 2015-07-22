#include "pch.h"
#include "Mat.h"

using namespace cvRT;

Mat::Mat()
{
    m_rawMatHolder = new cv::Mat();
}

Mat::Mat(cv::Mat& rawMat)
{
    m_rawMatHolder = &rawMat;
}
unsigned int Mat::total()
{
    return m_rawMatHolder->total();
}
