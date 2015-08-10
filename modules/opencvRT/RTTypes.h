// #TBD copyrights stuffs

#pragma once

namespace cvRT
{
    // cv::Scalar 
    public ref class Scalar sealed
    {
    public:
        Scalar(double val0, double val1, double val2, double val3)
        {
            cvScalar = new cv::Scalar(val0, val1, val2, val3);
        }

    internal:
        cv::Scalar GetCvScalar() { return *cvScalar; }

    private:
        cv::Scalar* cvScalar;
    };

    // cv::Point 
    public ref class Point sealed
    {
    public:
        Point(int p0, int p1)
        {
            cvPoint = new cv::Point(p0, p1);
        }

    internal:
        cv::Point GetCvPoint() { return *cvPoint; }

    private:
        cv::Point* cvPoint;
    };

    // cv::Rect 
    public ref class Rect sealed
    {
    public:
        property int X
        {
            int get() { return cvRect->x; }
        }

        property int Y
        {
            int get() { return cvRect->y; }
        }

        property int Width
        {
            int get() { return cvRect->width; }
        }

        property int Height
        {
            int get() { return cvRect->height; }
        }

        Rect(int x, int y, int width, int height)
        {
            cvRect = new cv::Rect(x, y, width, height);
        }

    internal:
        Rect(cv::Rect& rect)
        {
            cvRect = &rect;
        }

        cv::Rect GetCvRect() { return *cvRect; }

    private:
        cv::Rect* cvRect;
    };
    
    // cv::Size
    public ref class Size sealed
    {
    public:
        property int Width
        {
            int get() {return cvSize->width; }
        }

        property int Height
        {
            int get() { return cvSize->height; }
        }

        Size(int width, int height)
        {
            cvSize = new cv::Size(width, height);
        }

    internal:
        cv::Size GetCvSize() { return *cvSize; }

    private:
        cv::Size* cvSize;
    };    
}
