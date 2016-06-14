cmake_minimum_required(VERSION 3.5)
project(Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.hpp BinaryTree.cpp BinaryTree.hpp)
add_executable(Tree ${SOURCE_FILES})