cmake_minimum_required(VERSION 3.5)
project(Strings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Sentence.cpp Sentence.hpp)
add_executable(Strings ${SOURCE_FILES})