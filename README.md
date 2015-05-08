### OpenCV: Open Source Computer Vision Library

[![Gittip](http://img.shields.io/gittip/OpenCV.png)](https://www.gittip.com/OpenCV/)

### How to build:

1. Set ```OPENCV_TEST_DATA_PATH``` environment variable to location of ```opencv_extra/testdata``` to get tests work correctly. Also, set ```OPENCV_PERF_VALIDATION_DIR``` environment variable in case you are planning to run performance tests.
2. Install VS2015 RC from [there](https://www.visualstudio.com/).  Select "Universal Windows App Development Tools" using Custom setup option.
3. Jump to **Short way** or **Long way** depending on your aims and preferences

#### Short way (using pregenerated projects):
**Note:** 
Use pregenerated projects from bin_VS2015_RC folder if you are working with Visual Studio 2015 RC (Version 14.0.22823.1 D14REL) on Windows 10 OS (build 10074 or 10075).
Use pregenerated projects from bin folder if you are still working with Visual Studio 2015 CTP6 (Version 14.0.22609.0 D14REL).
These projects were tested with specific versions of Visual Studio 2015 and might not work correctly with other pre-release versions.

1. Set environment variable ```OCV2015_ROOT``` to the OpenCV location (e.g. ```Path\to\OCV\opencv```)
2. Jump to **Common build steps**

#### Long way (generating projects on your own):

1. Clone https://github.com/Microsoft/CMake.git
2. Checkout feature/Win10 branch
3. Build CMake for Windows
4. Create "bin" directory and cd to it
5. Run command ```Path\To\New CMake\bin\Release\cmake.exe -G "Visual Studio 14 2015 Win64" -DCMAKE_SYSTEM_NAME:String=WindowsStore -DCMAKE_SYSTEM_VERSION:String="10.0" -DCMAKE_VS_EFFECTIVE_PLATFORMS:String=x64 -DCMAKE_INSTALL_PREFIX:PATH=C:\Users\ocv_install ..```

#### Common build steps:

1. Open solution, change configuration to Release and build it

2. Running tests:
 
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
