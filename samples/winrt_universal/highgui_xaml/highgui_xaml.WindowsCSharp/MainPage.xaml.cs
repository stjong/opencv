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
using VideoIoCx;

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
        private readonly VideoIo _videoIoCx;

        /// <summary>
        /// 
        /// </summary>
        public MainPage()
        {
            this.InitializeComponent();

            _videoIoCx = new VideoIo();
            _videoIoCx.Initialize();
            _videoIoCx.SetImage(OCVImage);

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

            var selectedIndex = cb.SelectedIndex;
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

            _videoIoCx.StartCapture();

            while (true)
            {
                var mat = new MatCx();
                _videoIoCx.GetFrame(mat);
                _videoIoCx.ShowFrame(mat);
            }

            _videoIoCx.StopCapture();
        }
    }
}
