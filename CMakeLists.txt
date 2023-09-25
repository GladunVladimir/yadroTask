cmake_minimum_required(VERSION 3.26)
project(yadroTask)

set(CMAKE_CXX_STANDARD 17)

# tell CMake to generate config.h
configure_file (
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(yadroTask main.cpp
        Tape.h
        Tape.cpp
        Sort.h
        Sort.cpp
        config.h.in
        config.h
)
