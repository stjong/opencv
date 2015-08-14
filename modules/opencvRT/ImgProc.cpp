// tbd copyrights stuffs

#include "pch.h"
#include "ImgProc.h"

using namespace cvRT;

///////////////////////////////////////////////////////////////////////////////
void ImgProc::cvtColor(Mat^ srcImg, Mat^ destImg, ColorConversionCodes conversionCode)
{
    cv::cvtColor(srcImg->RawMat(), destImg->RawMat(), (int)conversionCode);
}

///////////////////////////////////////////////////////////////////////////////
void ImgProc::GaussianBlur(Mat^ src, Mat^ dst, cvRT::Size^ ksize, double sigmaX)
{
    GaussianBlur(src, dst, ksize, sigmaX, 0);
}

///////////////////////////////////////////////////////////////////////////////
void ImgProc::GaussianBlur(Mat ^ src, Mat ^ dst, cvRT::Size^ ksize, double sigmaX, double sigmaY)
{    
    cv::GaussianBlur(src->RawMat(), dst->RawMat(), ksize->GetCvSize(), sigmaX, sigmaY);
}

///////////////////////////////////////////////////////////////////////////////
void ImgProc::Canny(Mat^ src, Mat^ dst, double threshold1, double threshold2)
{
    Canny(src, dst, threshold1, threshold2, 3, false);
}

///////////////////////////////////////////////////////////////////////////////
void ImgProc::Canny(Mat^ src, Mat^ dst, double threshold1, double threshold2, int apertureSize)
{
    Canny(src, dst, threshold1, threshold2, apertureSize, false);
}

///////////////////////////////////////////////////////////////////////////////
void ImgProc::Canny(Mat^ src, Mat^ dst, double threshold1, double threshold2, int apertureSize, bool L2gradient)
{
    cv::Canny(src->RawMat(), dst->RawMat(), threshold1, threshold2, apertureSize, L2gradient);
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::EqualizeHist(Mat^ src, Mat^ dst)
{
    cv::equalizeHist(src->RawMat(), dst->RawMat());
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::Ellipse(Mat^ src, Point^ center, cvRT::Size^ axes, double angle, double start_angle, double end_angle, Scalar^ scalar, int thickness, int line_type, int shift)
{
    cv::ellipse(src->RawMat(), center->GetCvPoint(), axes->GetCvSize(), angle, start_angle, end_angle, scalar->GetCvScalar(), thickness, line_type, shift);
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::Circle(Mat^ src, Point^ center, int radius, Scalar^ scalar, int thickness, int line_type, int shift)
{
    cv::circle(src->RawMat(), center->GetCvPoint(), radius, scalar->GetCvScalar(), thickness, line_type, shift);
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::FindContours(_In_ Mat^ image, _Out_ IVector<IVector<Point^>^>^ contours, _Out_ IVector<Vec4i^>^ hierarchy, _In_ ContourRetrievalAlgorithm mode, _In_ ContourApproximationModes method, _In_ Point^ offset)
{
    std::vector<std::vector<cv::Point>> cvContours;
    std::vector<cv::Vec4i> cvHierarchy;

    cv::findContours(image->RawMat(), cvContours, cvHierarchy, (int)mode, (int)method, offset->GetCvPoint());

    for (std::vector<std::vector<cv::Point>>::iterator it = cvContours.begin(); it != cvContours.end(); it++)
    {
        // std::Vector<cvRT::Point^>^ newVector = new 

        for (std::vector<cv::Point>::iterator it2 = it->begin(); it2 != it->end(); it2++)
        {



        }
    }
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::DrawContours(Mat ^ image, IVector<IVector<Point^>^>^ contours, int contourIdx, Scalar ^ color, int thickness, int lineType, IVector<Vec4i^>^ hierarchy, int maxLevel, Point ^ offset)
{
    
    
}

/*
void cvRT::ImgProc::findContours(Mat ^ image, IVector<IVector<Point>^>^ contours, int mode, int method, Point offset)
{    
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
}

void cvRT::ImgProc::findContours(Mat ^ image, IVector<IVector<Point>^>^ contours, Mat ^ hierarchy, int mode, int method, Point offset)
{    
    cv::findContours(image->RawMat(), contours, hierarchy->RawMat(), mode, method, cv::Point(offset.X, offset.Y));
}

void cvRT::ImgProc::drawContours(Mat ^ image, IVector<IVector<Point>^>^ contours, int contourIdx, Windows::UI::Color color, int thickness, int lineType, Mat ^ hierarchy, int maxLevel, Point offset)
{    
    cv::drawContours(image->RawMat(), contours, contourIdx, cv::Scalar(color.R, color.G, color.B), thickness, lineType, hierarchy->RawMat(), maxLevel, cv::Point(offset.X, offset.Y));

}
*/

