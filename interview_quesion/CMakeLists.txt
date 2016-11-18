project(InterviewQuestion)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++11")


# fork_test.cpp
set(fork_test_SRC fork_test.cpp)
add_executable(fork_test ${fork_test_SRC})


# class_derive.cpp
set(class_derive_SRC class_derive.cpp)
add_executable(class_derive ${class_derive_SRC})
