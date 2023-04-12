cmake_minimum_required(VERSION 3.24)

add_subdirectory(intan)

add_library(neural-recording-controller SHARED intan/evalBoard.cpp intan/evalBoard.h)

target_link_libraries(neural-recording-controller PRIVATE ${okFrontPanel_LIBRARY})