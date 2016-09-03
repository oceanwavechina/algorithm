project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

# Problem1.cpp
set(Problem1_SRC Problem1.cpp)
add_executable(Problem1 ${Problem1_SRC})
