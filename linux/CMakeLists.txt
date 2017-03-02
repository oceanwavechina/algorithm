project(Linux)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++11")

# mmap_copy_files.cpp
set(mmap_copy_files_SRC mmap_copy_files.cpp)
add_executable(mmap_copy_files ${mmap_copy_files_SRC})

# select_server.cpp
set(select_server_SRC select_server.cpp)
add_executable(select_server ${select_server_SRC})

# socket_client.cpp
set(socket_client_SRC socket_client.cpp)
add_executable(socket_client ${socket_client_SRC})

# mutex_and_condition_var.cpp
set(mutex_and_condition_var_SRC mutex_and_condition_var.cpp)
add_executable(mutex_and_condition_var ${mutex_and_condition_var_SRC})
target_link_libraries(mutex_and_condition_var pthread) 

# epoll.c
set(epoll_SRC epoll.c)
add_executable(epoll ${epoll_SRC})

