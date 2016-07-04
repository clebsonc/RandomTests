cmake_minimum_required(VERSION 3.5)
project(Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Sort.cpp
    Sort.hpp Employee.cpp Employee.hpp)

add_executable(Sort ${SOURCE_FILES})