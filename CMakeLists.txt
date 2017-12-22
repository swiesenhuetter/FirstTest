cmake_minimum_required(VERSION 3.6)
project(FirstTest)

set (CMAKE_CXX_FLAGS "-O0")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Test_OptVal.cpp OptVal.h catch.hpp)

add_executable(FirstTest ${SOURCE_FILES})