#include "pch.h"
#include "AppMain.h"
#include "MainPage.g.h"

using namespace VideoCapture;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Microsoft::WRL;
using namespace Windows::Media::MediaProperties;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Storage::Streams;

using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::System;
using namespace Windows::UI;
using namespace Windows::UI::Core;
using namespace Windows::Storage;
using namespace Windows::Devices::Enumeration;
using namespace concurrency;


#include <opencv2\videoio\cap_winrt\WinRTVideoCapture.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\videoio.hpp>
#include <memory>

static const int sWidth = 640;
static const int sHeight = 360;

AppMain::AppMain(Image^ image)
    : m_image(image)
    , m_width(sWidth)
    , m_height(sHeight)
{
    image->Width = sWidth;
    image->Height = sHeight;
}

AppMain::~AppMain()
{

}

inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        throw Exception::CreateException(hr);
    }
}

// Helper function to get pointer to WriteableBitmap pixel buffer
byte* GetPointerToPixelData(IBuffer^ buffer)
{
    // Cast to Object^, then to its underlying IInspectable interface.
    Object^ obj = buffer;
    ComPtr<IInspectable> insp(reinterpret_cast<IInspectable*>(obj));

    // Query the IBufferByteAccess interface.
    ComPtr<IBufferByteAccess> bufferByteAccess;
    ThrowIfFailed(insp.As(&bufferByteAccess));

    // Retrieve the buffer data.
    byte* pixels = nullptr;
    ThrowIfFailed(bufferByteAccess->Buffer(&pixels));
    return pixels;
}

void AppMain::start(int width, int height)
{
    m_width = width;
    m_height = height;
    start();
}

void AppMain::start()
{
    // create a WriteableBitmap
    m_bitmap = ref new WriteableBitmap(m_width, m_height);

    // create the Video Capture device
    cv::VideoCapture cap(0); // open the default camera
    auto hcap = std::make_shared<cv::VideoCapture>(cap);

    const std::function<void(const cv::Mat& mat)>& callback = [this](const cv::Mat& mat)
    {
        if (mat.empty()) return;

        // copy processed image into the WriteableBitmap
        // Fails here with:
        //   First-chance exception at 0x76BD4598 (KernelBase.dll) in VideoCapture.Windows.exe: 0x40080201: WinRT originate error (parameters: 0x8001010E, 0x00000051, 0x063AE5F4).
        //   Microsoft C++ exception : Platform::WrongThreadException ^ at memory location 0x063AEA94.HRESULT : 0x8001010E 
        //   The application called an interface that was marshalled for a different thread.
        auto buffer = m_bitmap->PixelBuffer;
        auto pointer = GetPointerToPixelData(buffer);
        memcpy(pointer, mat.data, m_width * m_height * mat.step.buf[1]);

        // display the image
        m_image->Source = m_bitmap;
        m_bitmap->Invalidate();
    };

    auto workItem = ref new Windows::System::Threading::WorkItemHandler(
        [this, hcap, callback](IAsyncAction^ workItem)
    {
        cv::Mat edges;
        for (;;)
        {
            cv::Mat frame;
            *hcap >> frame; // get a new frame from camera

            if (frame.empty()) continue;

            callback(frame);
        }
    });

    auto asyncAction = Windows::System::Threading::ThreadPool::RunAsync(workItem);

    //m_capture = WinRTVideoCapture::create(m_width, m_height);

    //// start capturing video. Callback will happen on the UI thread
    //m_capture->start([this](const cv::Mat& mat) {
    //    // convert to grayscale
    //    cv::Mat intermediateMat;
    //    cv::cvtColor(mat, intermediateMat, CV_RGB2GRAY);

    //    // convert to BGRA
    //    cv::Mat output;
    //    cv::cvtColor(intermediateMat, output, CV_GRAY2BGRA);

    //    // copy processed image into the WriteableBitmap
    //    memcpy(GetPointerToPixelData(m_bitmap->PixelBuffer), output.data, m_width * m_height * 4);

    //    // display the image
    //    m_image->Source = m_bitmap;
    //    m_bitmap->Invalidate();
    //});
}

void AppMain::stop()
{

}
