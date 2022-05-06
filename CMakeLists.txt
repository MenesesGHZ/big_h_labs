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

# add utils
add_library(utils lib/utils.cpp)
target_include_directories(utils PUBLIC lib)

# add utils
add_library(rabin_karp_search lib/rabin_karp_search.cpp)
target_include_directories(rabin_karp_search PUBLIC lib)
target_link_libraries(rabin_karp_search PUBLIC utils)

# include labrary to executable
target_link_libraries(labs PUBLIC lab rabin_karp_search)
target_include_directories(labs PUBLIC "${PROJECT_BINARY_DIR}")