cmake_minimum_required(VERSION 3.5.1)

# set the project name
project(labs VERSION 1.0)

# define binary
add_executable(labs main.cpp)

# specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add laboratories assigments as a library
add_library(lab lib/lab.cpp)
target_include_directories(lab PUBLIC lib)

# include labrary to executable
target_link_libraries(labs PUBLIC lab)
target_include_directories(labs PUBLIC "${PROJECT_BINARY_DIR}")