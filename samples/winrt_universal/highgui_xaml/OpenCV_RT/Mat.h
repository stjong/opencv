#pragma once

namespace cvRT
{
    public ref class Mat sealed
    {
    public:
        Mat();
        unsigned int total();

    internal:
        Mat(cv::Mat& rawMat);
        cv::Mat& RawMat()
        {
            return *m_rawMatHolder;
        }

    private:
        cv::Mat* m_rawMatHolder;
    };
}

