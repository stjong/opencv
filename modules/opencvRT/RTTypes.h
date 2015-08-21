// #TBD copyrights stuffs

#pragma once

namespace cvRT
{    
    // 
    // cv::Scalar    
    //
    public ref class Scalar sealed
    {
    public:
        Scalar(double val0, double val1, double val2, double val3) { cvScalar = cv::Scalar(val0, val1, val2, val3); }        
        Scalar(double val0, double val1, double val2) { cvScalar = cv::Scalar(val0, val1, val2); }
        Scalar(double val0, double val1) { cvScalar = cv::Scalar(val0, val1); }       
        Scalar(double val0) { cvScalar = cv::Scalar(val0); }
    internal:
        cv::Scalar& Get() { return cvScalar; }
    private:
        cv::Scalar cvScalar;
    };

    //
    // cv::Point 
    //
    public ref class Point sealed
    {
    public:
        Point(int p0, int p1) { cvPoint = cv::Point(p0, p1); }
    internal:
        cv::Point& Get() { return cvPoint; }
    private:
        cv::Point cvPoint;
    };

    //
    // cv::Rect 
    //
    public ref class Rect sealed
    {
    public:
        property int X { int get() { return cvRect.x; }}
        property int Y { int get() { return cvRect.y; }}
        property int Width { int get() { return cvRect.width; }}
        property int Height {int get() { return cvRect.height; }}
        Rect(int x, int y, int width, int height) { cvRect = cv::Rect(x, y, width, height); }
    internal:
        cv::Rect& Get() { return cvRect; }
    private:
        cv::Rect cvRect;
    };
    
    //
    // cv::Size
    //
    public ref class Size sealed
    {
    public:
        property int Width { int get() {return cvSize.width; }}
        property int Height { int get() { return cvSize.height; }}
        Size(int width, int height) {cvSize = cv::Size(width, height);}
    internal:
        cv::Size& GetCvSize() { return cvSize; }
    private:
        cv::Size cvSize;
    };  

    //
    // Comment TBD
    //
    public ref class VectorOfPoint sealed
    {
    public:
        VectorOfPoint() { ; }
    internal:
    private:
        std::vector<cv::Point> cvVoPoint;
    };

    //
    // Comment TBD
    //
    public ref class VectorOfVec4i sealed
    {
    public:
        VectorOfVec4i() { cvVecV4i = new std::vector<cv::Vec4i>(); }
    internal:
        std::vector<cv::Vec4i>& Get() { return *cvVecV4i; }
    private:
        std::vector<cv::Vec4i>* cvVecV4i;
    };
    
    //
    // Commment TBD
    // 
    public ref class VectorOfVectorOfPoint sealed
    {
    public:
        VectorOfVectorOfPoint() { ; }
        int Count() { return cvVoVoPoint.size(); }

        // tbd
        void Index(int index) 
        { 
            
        }        
    internal:
        std::vector<std::vector<cv::Point>>& Get() { return cvVoVoPoint; }
    private:
        std::vector<std::vector<cv::Point>> cvVoVoPoint;
    };

    
    /*
    //
    // cv::Vec4i
    //
    public ref class Vec4i sealed
    {
    public:
    Vec4i(int i1, int i2, int i3, int i4)
    {
    cvVec4i = new cv::Vec4i(i1, i2, i3, i4);
    }

    internal:
    Vec4i(cv::Vec4i& x)
    {
    cvVec4i = new cv::Vec4i(x);
    }

    cv::Vec4i GetVec4i() { return *cvVec4i; }

    private:
    cv::Vec4i* cvVec4i;
    };
        
    ///////////////////////////////////////////////////////////////////////////
    // cv::InputArray
    public ref class InputArray sealed
    {
    public:
        
    internal:
        cv::InputArray GetCvInputArray() { return cvInputArray; }

    private:
        cv::_InputArray cvInputArray;
    };

    ///////////////////////////////////////////////////////////////////////////
    // cv::OutputArray
    public ref class OutputArray sealed
    {
    public:

    internal:
        cv::OutputArray GetCvOutputArray() { return cvOutputArray; }

    private:
        cv::_OutputArray cvOutputArray;
    };    

    ///////////////////////////////////////////////////////////////////////////
    // cv::InputOutputArray
    public ref class InputOutputArray sealed
    {
    public:

    internal:
        cv::InputOutputArray GetCvInputOutputArray() { return cvInputOutputArray; }
    private:
        cv::_InputOutputArray cvInputOutputArray;
    };


    ///////////////////////////////////////////////////////////////////////////
    // cv::InputArrayOfArrays
    public ref class InputArrayOfArrays sealed
    {
    public:

    internal:
        cv::InputArrayOfArrays GetCvInputArrayOfArrays() { return cvInputArrayOfArrays; }

    private:
        cv::_InputArray cvInputArrayOfArrays;
    };


    ///////////////////////////////////////////////////////////////////////////
    // cv::OutputArrayOfArrays
    public ref class OutputArrayOfArrays sealed
    {
    public:

    internal:
        cv::OutputArrayOfArrays GetCvOutputArrayOfArrays() { return cvOutputArrayOfArrays; }

    private:
        cv::_OutputArray cvOutputArrayOfArrays;
    };

    */


}
