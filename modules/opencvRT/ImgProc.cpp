// tbd copyrights stuffs

#include "pch.h"
#include "collection.h"
#include "ImgProc.h"


using namespace cvRT;

//
// function for cv::cvtColor
//
void ImgProc::cvtColor(Mat^ srcImg, Mat^ destImg, ColorConversionCodes conversionCode)
{
    cv::cvtColor(srcImg->RawMat(), destImg->RawMat(), (int)conversionCode);
}

//
// function for cv::cvtColor
//
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
    cv::ellipse(src->RawMat(), center->Get(), axes->GetCvSize(), angle, start_angle, end_angle, scalar->Get(), thickness, line_type, shift);
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::Circle(Mat^ src, Point^ center, int radius, Scalar^ scalar, int thickness, int line_type, int shift)
{
    cv::circle(src->RawMat(), center->Get(), radius, scalar->Get(), thickness, line_type, shift);
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::FindContours(Mat^ image, VectorOfVectorOfPoint^ contours, VectorOfVec4i^ hierarchy, ContourRetrievalAlgorithm mode, ContourApproximationModes method, Point^ offset)
{   
    cv::findContours(image->RawMat(), contours->Get(), hierarchy->Get(), (int)mode, (int)method, offset->Get());
}

///////////////////////////////////////////////////////////////////////////////
void cvRT::ImgProc::DrawContours(Mat^ image, VectorOfVectorOfPoint^ contours, int contourIdx, Scalar^ color, int thickness, int lineType, VectorOfVec4i^ hierarchy, int maxLevel, Point^ offset)
{
    cv::drawContours(image->RawMat(), contours->Get(), contourIdx, color->Get(), thickness, lineType, hierarchy->Get(), maxLevel, offset->Get());
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

