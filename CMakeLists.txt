cmake_minimum_required(VERSION 3.24)

project(neural-recording-controller VERSION 0.1.0)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Best practice for rpath from Professional Cmake
#set before defining library.
#alternatively I think we can use set target properties after library is defined
if(APPLE)
        set(base @loader_path)
else()
        set(base $ORIGIN)
endif()

include(GNUInstallDirs)
file(RELATIVE_PATH relDir
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}
)
set(CMAKE_INSTALL_RPATH ${base} ${base}/${relDir})

#set(VCPKG_MANIFEST_MODE ON)


add_subdirectory(neural-recording-controller)

#Setup Testing
include(CTest)

if (BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
