#pragma once
namespace cvRT
{
    public ref class HighGui sealed
    {
    public:
        HighGui();

        static void imshow(cvRT::Mat^ img);
    };
}

