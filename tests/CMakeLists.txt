cmake_minimum_required(VERSION 3.24)

include(FetchContent)
FetchContent_Declare(Catch2
  QUIET
  URL https://github.com/catchorg/Catch2/archive/v3.3.2.tar.gz
)
FetchContent_MakeAvailable(Catch2)

add_executable(neural_recording_test_suite
    test_main.cpp
)

target_link_libraries(neural_recording_test_suite
    PRIVATE
    neural-recording-controller
    Catch2::Catch2WithMain
)

target_include_directories(neural_recording_test_suite
    PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/neural-recording-controller/intan
)

set(TEST_HARDWARE_INTAN FALSE)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

#This was in Testing section of Craig Scott's Professional CMake book
#https://stackoverflow.com/questions/59376924/ctest-cmake-mingw-executables-build-but-fail-to-run-because-fresh-dll-is-n
function(add_test_with_dll test_name test_cmd)

    add_test(NAME ${test_name} COMMAND neural_recording_test_suite ${test_cmd})
    if (WIN32)
        set(FrontPanelDir "${PROJECT_SOURCE_DIR}/neural-recording-controller/intan/Resources/FrontPanel")
        set(neuralRecordingDir "$<SHELL_PATH:$<TARGET_FILE_DIR:neural-recording-controller>>")
        set_property(TEST ${test_name} APPEND PROPERTY ENVIRONMENT_MODIFICATION
        PATH=path_list_prepend:${FrontPanelDir}
        PATH=path_list_prepend:${neuralRecordingDir}
        )
    endif()
endfunction()

add_test_with_dll(first_test "[evalBoard]")

