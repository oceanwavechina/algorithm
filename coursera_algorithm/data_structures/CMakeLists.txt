project(DataStructures)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

###########  WEEK 2  ###########
# heaps.cpp
set(heaps_SRC heaps.cpp)
add_executable(heaps ${heaps_SRC})

