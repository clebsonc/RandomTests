cmake_minimum_required(VERSION 3.5)
project(Concurrency)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES
    HelloWord.cpp)

add_executable(Concurrency ${SOURCE_FILES})