project(Linux)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++11")


# test.cpp
set(test_SRC test.cpp)
add_executable(test_01 ${test_SRC})


# mmap_copy_files.cpp
set(mmap_copy_files_SRC mmap_copy_files.cpp)
add_executable(mmap_copy_files ${mmap_copy_files_SRC})


# select_server.cpp
set(select_server_SRC select_server.cpp)
add_executable(select_server ${select_server_SRC})


# socket_client.cpp
set(socket_client_SRC socket_client.cpp)
add_executable(socket_client ${socket_client_SRC})

