# CMake script for pp6calculator-reborn

# Require the latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Declare the project!
project(pp6calculator)

# standard flags. (if they're so standard, why are they not default?!)
if(CMAKE_COMPLIER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++98 -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

# includes
include_directories(pp6libs)
include_directories(FileReader-1.0.0)

# add the library
add_subdirectory(pp6libs)
add_subdirectory(FileReader-1.0.0)

# add the pp6calculator program
add_executable(pp6calculator pp6calculator.cpp)

# link 'em
target_link_libraries(pp6calculator pp6libs FileReader)

# installing into bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# package sources and executable
include(CPack)