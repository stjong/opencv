#pragma once
namespace cvRT
{
    public ref class VideoCapture sealed
    {
    public:
        VideoCapture();
        bool open(int device = 0);
        bool retrieve(cvRT::Mat^ frame);
        bool grab();
    private:
        cv::VideoCapture m_rawVideoCapture;
    };
}