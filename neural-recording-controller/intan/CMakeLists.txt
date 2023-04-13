cmake_minimum_required(VERSION 3.24)

find_library(okFrontPanel_LIBRARY okFrontPanel PATHS ${CMAKE_CURRENT_LIST_DIR}/Resources/FrontPanel)

message(STATUS ${okFrontPanel_LIBRARY})