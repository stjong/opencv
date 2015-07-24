using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.System.Threading;
using Windows.UI.Core;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using System.Threading;
using cvRT;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace highgui_xaml.WindowsCSharp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        /// <summary>
        /// 
        /// </summary>
        private readonly VideoIo _videoIo;

        private int _processingMethodIndex;

        /// <summary>
        /// 
        /// </summary>
        public MainPage()
        {
            this.InitializeComponent();

            _videoIo = new VideoIo();
            _videoIo.Initialize();
            _videoIo.SetImage(OCVImage);

            ThreadPool.RunAsync(new WorkItemHandler((IAsyncAction) => CvMainThread()));
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void comboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var cb = (ComboBox)sender;

            _processingMethodIndex = cb.SelectedIndex;
            var selectedItem = ((ComboBoxItem)cb.SelectedItem).Content.ToString();

            Debug.WriteLine(selectedItem);

            // TBD[stjong] change the processing here.
        }

        /// <summary>
        /// 
        /// </summary>
        public void CvMainThread()
        {
            // TBD need exit event.

            _videoIo.StartCapture();
            _videoIo.StartCapture();

            while (true)
            {
                var srcFrame = new Mat();
                var dstFrame = new Mat();
                _videoIo.GetFrame(srcFrame);

                switch (_processingMethodIndex)
                {
                    // passthrough
                    case 0:
                        break;
                    // gray
                    case 1:
                        ImgProc.cvtColor(srcFrame, dstFrame, ColorConversionCodes.COLOR_RGBA2GRAY);
                        ImgProc.cvtColor(dstFrame, srcFrame, ColorConversionCodes.COLOR_GRAY2RGB);
                        break;
                    // canny
                    case 3:
                        ImgProc.cvtColor(srcFrame, dstFrame, cvRT.ColorConversionCodes.COLOR_RGBA2GRAY);
                        ImgProc.GaussianBlur(dstFrame, dstFrame, new Size(7, 7), 1.5, 1.5);
                        ImgProc.Canny(dstFrame, dstFrame, 0, 30, 3);
                        ImgProc.cvtColor(dstFrame, srcFrame, ColorConversionCodes.COLOR_GRAY2RGB);
                        break;
                    default:
                        break;
                }
                _videoIo.ShowFrame(srcFrame);
                Task.Delay(TimeSpan.FromMilliseconds(500));
            }
        }
    }
}
