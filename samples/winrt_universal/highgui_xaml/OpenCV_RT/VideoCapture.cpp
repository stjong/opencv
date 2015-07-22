#include "pch.h"
#include "Mat.h"
#include "VideoCapture.h"

using namespace cvRT;

VideoCapture::VideoCapture()
{
}

bool VideoCapture::open(int device)
{
    return m_rawVideoCapture.open(device);
}

bool VideoCapture::retrieve(cvRT::Mat^ frame)
{
    return m_rawVideoCapture.retrieve(frame->RawMat());
}

bool VideoCapture::grab()
{
    return m_rawVideoCapture.grab();
}