project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

# binary_search_STL.cpp
set(binary_search_STL_SRC binary_search_STL.cpp)
add_executable(binary_search_STL ${binary_search_STL_SRC})
