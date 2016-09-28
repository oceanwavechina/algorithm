project(DataStructures)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

###########  WEEK 2  ###########
# heaps_sort.cpp
set(heaps_sort_SRC heaps_sort.cpp)
add_executable(heaps_sort ${heaps_sort_SRC})

# heaps_sort_zero_based.cpp
set(heaps_sort_zero_based_SRC heaps_sort_zero_based.cpp)
add_executable(heaps_sort_zero_based ${heaps_sort_zero_based_SRC})

