project(AlgorithmBOX)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

# sum_of_three_numbers.cpp
set(sum_of_three_numbers_SRC sum_of_three_numbers.cpp)
add_executable(sum_of_three_numbers ${sum_of_three_numbers_SRC})

# string_rotate.cpp
set(string_rotate_SRC string_rotate.cpp)
add_executable(string_rotate ${string_rotate_SRC})


