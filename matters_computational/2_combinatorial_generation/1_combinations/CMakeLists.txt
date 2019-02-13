project(combinations)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++14")

if(0)



endif(0)


# 1_binomial_coefficients.cpp
set(1_binomial_coefficients_SRC 1_binomial_coefficients.cpp)
add_executable(1_binomial_coefficients ${1_binomial_coefficients_SRC})
