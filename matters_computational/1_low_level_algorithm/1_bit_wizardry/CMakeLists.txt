project(bit_wizardry)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++14")

if(0)

# 1_triva.cpp
set(1_triva_SRC 1_triva.cpp)
add_executable(1_triva ${1_triva_SRC})


endif(0)


# 2_operation_on_lower_bits.cpp
set(2_operation_on_lower_bits_SRC 2_operation_on_lower_bits.cpp)
add_executable(2_operation_on_lower_bits ${2_operation_on_lower_bits_SRC})
