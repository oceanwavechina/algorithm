project(AlgorithmBOX)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++14")

if(0)

endif(0)


# 1_triva.cpp
set(1_triva_SRC 1_triva.cpp)
add_executable(1_triva ${1_triva_SRC})
