# CMake script for pp6calculator-reborn

# Require the latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Declare the project!
project(pp6calculator)

# add the pp6calculator program
add_executable(pp6calculator pp6calculator.cpp)