# Install script for directory: C:/Users/evgen/Documents/SamplesVS2015/master/opencv/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/ocv_install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/calib3d/.calib3d/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/core/.core/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudaarithm/.cudaarithm/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudabgsegm/.cudabgsegm/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudacodec/.cudacodec/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudafeatures2d/.cudafeatures2d/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudafilters/.cudafilters/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudaimgproc/.cudaimgproc/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudalegacy/.cudalegacy/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudaobjdetect/.cudaobjdetect/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudaoptflow/.cudaoptflow/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudastereo/.cudastereo/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudawarping/.cudawarping/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/cudev/.cudev/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/features2d/.features2d/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/flann/.flann/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/hal/.hal/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/highgui/.highgui/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/imgcodecs/.imgcodecs/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/imgproc/.imgproc/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/java/.java/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/ml/.ml/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/objdetect/.objdetect/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/photo/.photo/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/python/.python/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/shape/.shape/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/stitching/.stitching/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/superres/.superres/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/ts/.ts/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/video/.video/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/videoio/.videoio/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/videostab/.videostab/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/viz/.viz/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/world/.world/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/hal/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/core/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/flann/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/imgproc/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/ml/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/objdetect/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/photo/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/video/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/features2d/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/imgcodecs/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/shape/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/videoio/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/calib3d/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/stitching/cmake_install.cmake")
  include("C:/Users/evgen/Documents/SamplesVS2015/master/opencv/vs2015/WS/10.0/x86/modules/videostab/cmake_install.cmake")

endif()

