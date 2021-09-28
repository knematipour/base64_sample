cmake_minimum_required(VERSION 3.20)
project(test_base64_source)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_base64_source main.cpp base64.cpp base64.h)
