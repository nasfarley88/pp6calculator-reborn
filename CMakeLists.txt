# CMake script for pp6calculator-reborn

# Require the latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Declare the project!
project(pp6calculator)

# includes
include_directories(pp6libs)

# add the pp6calculator program
add_executable(pp6calculator pp6calculator.cpp)