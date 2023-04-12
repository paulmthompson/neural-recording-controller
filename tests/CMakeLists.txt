cmake_minimum_required(VERSION 3.24)

add_executable(neural_recording_test_suite
    test_main.cpp
)

target_link_libraries(neural_recording_test_suite
    PRIVATE
    neural-recording-controller
)

target_include_directories(neural_recording_test_suite
    PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/neural-recording-controller/intan
)

# define tests
add_test(
  NAME first_test
  COMMAND $<TARGET_FILE:neural_recording_test_suite>
  )

#This was in Testing section of Craig Scott's Professional CMake book
#https://stackoverflow.com/questions/59376924/ctest-cmake-mingw-executables-build-but-fail-to-run-because-fresh-dll-is-n
if (WIN32)
    #set_tests_properties(neural_recording_test_suite PROPERTIES ENVIRONMENT "PATH=${CMAKE_BINARY_DIR}/neural-recording-controller;$ENV{PATH}")
    set(FrontPanelDir "${PROJECT_SOURCE_DIR}/neural-recording-controller/intan/Resources/FrontPanel")
    set(neuralRecordingDir "$<SHELL_PATH:$<TARGET_FILE_DIR:neural-recording-controller>>")
    message(STATUS ${neuralRecordingDir})
    message(STATUS ${neuralRecordingDir})
    set_property(TEST first_test APPEND PROPERTY ENVIRONMENT_MODIFICATION
    PATH=path_list_prepend:${FrontPanelDir}
    PATH=path_list_prepend:${neuralRecordingDir}
    )
endif()

message(STATUS $ENV{PATH})