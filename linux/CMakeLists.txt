project(Linux)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++11")


# test.cpp
set(test_SRC test.cpp)
add_executable(test_01 ${test_SRC})


# mmap_copy_files.cpp
set(mmap_copy_files_SRC mmap_copy_files.cpp)
add_executable(mmap_copy_files ${mmap_copy_files_SRC})

