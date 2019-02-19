cmake_minimum_required(VERSION 3.13)
project(test_test)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
add_executable(test_test main.cpp pr1_sys.h)
target_link_libraries(test_test gtest)