#include "pch.h"

#include "ImgProc.h"

using namespace cvRT;

void ImgProc::cvtColor(Mat^ srcImg, Mat^ destImg, ColorConversionCodes conversionCode)
{
    cv::cvtColor(srcImg->RawMat(), destImg->RawMat(), (int)conversionCode);
}

void ImgProc::GaussianBlur(Mat^ src, Mat^ dst, Size ksize, double sigmaX)
{
    GaussianBlur(src, dst, ksize, sigmaX, 0);
}

void ImgProc::GaussianBlur(Mat ^ src, Mat ^ dst, Size ksize, double sigmaX, double sigmaY)
{
    cv::Size size(ksize.Width, ksize.Height);
    cv::GaussianBlur(src->RawMat(), dst->RawMat(), size, sigmaX, sigmaY);
}

void ImgProc::Canny(Mat^ src, Mat^ dst, double threshold1, double threshold2)
{
    Canny(src, dst, threshold1, threshold2, 3, false);
}

void ImgProc::Canny(Mat^ src, Mat^ dst, double threshold1, double threshold2, int apertureSize)
{
    Canny(src, dst, threshold1, threshold2, apertureSize, false);
}

void ImgProc::Canny(Mat^ src, Mat^ dst, double threshold1, double threshold2, int apertureSize, bool L2gradient)
{
    cv::Canny(src->RawMat(), dst->RawMat(), threshold1, threshold2, apertureSize, L2gradient);
}

void cvRT::ImgProc::findContours(Mat ^ image, IVector<IVector<Point>^>^ contours, int mode, int method, Point offset)
{
    /*
    std::vector<std::vector<cv::Point>> cvContours;
    for(IVector<Point>^ row : contours)
    {
        std::vector<cv::Point> newRow;
        for (Point col : row)
        {
            newRow.push_back(cv::Point(col.X, col.Y));
        }
        cvContours.push_back(newRow);
    }

    cv::findContours(image->RawMat(), cvContours, mode, method, cv::Point(offset.X, offset.Y));

    for(auto row : CvContour)
    */
}

void cvRT::ImgProc::findContours(Mat ^ image, IVector<IVector<Point>^>^ contours, Mat ^ hierarchy, int mode, int method, Point offset)
{
    /*
    cv::findContours(image->RawMat(), contours, hierarchy->RawMat(), mode, method, cv::Point(offset.X, offset.Y));
    */
}

void cvRT::ImgProc::drawContours(Mat ^ image, IVector<IVector<Point>^>^ contours, int contourIdx, Windows::UI::Color color, int thickness, int lineType, Mat ^ hierarchy, int maxLevel, Point offset)
{
    /*
    cv::drawContours(image->RawMat(), contours, contourIdx, cv::Scalar(color.R, color.G, color.B), thickness, lineType, hierarchy->RawMat(), maxLevel, cv::Point(offset.X, offset.Y));
    */
}
