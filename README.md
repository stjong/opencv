### OpenCV: Open Source Computer Vision Library

[![Gittip](http://img.shields.io/gittip/OpenCV.png)](https://www.gittip.com/OpenCV/)

#### Build notes

1. Set ```OPENCV_TEST_DATA_PATH``` environment variable to location of ```opencv_extra/testdata``` to get tests work correctly. Also, set ```OPENCV_PERF_VALIDATION_DIR``` environment variable in case you are planning to run performance tests.
2. Install VS2015 CTP6 from [there](https://www.visualstudio.com/en-us/downloads/visual-studio-2015-ctp-vs)
3. Install Windows 10 SDK from [there](https://dev.windows.com/en-US/windows-10-developer-preview-tools)
4. Clone https://github.com/Microsoft/CMake.git
5. Checkout feature/Win10 branch
6. Build CMake for Windows
7. Create "bin" directory and cd to it
8. Run command ```Path\To\New CMake\bin\Release\cmake.exe -G "Visual Studio 14 2015 Win64" -DCMAKE_SYSTEM_NAME:String=WindowsStore -DCMAKE_SYSTEM_VERSION:String="10.0" -DCMAKE_VS_EFFECTIVE_PLATFORMS:String=x64 -DCMAKE_INSTALL_PREFIX:PATH=C:\Users\ocv_install ..```
9. Open solution, change configuration to Release and build it

10. Running tests:
 
 - **Accuracy:** Run opencv_test_{module}.exe via console or as usual by double clicking it. You should see output in the console window
 - **Performance:** Run opencv_perf_{module}.exe via console or as usual by double clicking it. You should see output in the console window. In case you'd like to write test results to file use --perf_write_validation_results=<filename> parameter; To compare current results to previous use --perf_read_validation_results=<filename>. This should read/write files from/to ```OPENCV_PERF_VALIDATION_DIR```

#### Resources

* Homepage: <http://opencv.org>
* Docs: <http://docs.opencv.org>
* Q&A forum: <http://answers.opencv.org>
* Issue tracking: <http://code.opencv.org>

#### Contributing

Please read before starting work on a pull request: <http://code.opencv.org/projects/opencv/wiki/How_to_contribute>

Summary of guidelines:

* One pull request per issue;
* Choose the right base branch;
* Include tests and documentation;
* Clean up "oops" commits before submitting;
* Follow the coding style guide.
