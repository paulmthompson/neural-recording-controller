cmake_minimum_required(VERSION 3.21)

#add_subdirectory(intan)

add_library(neural-recording-controller SHARED intan/evalBoard.cpp intan/evalBoard.h)
