project(LeetCode)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++14")

# 01_two_sum.cpp
set(01_two_sum_SRC 01_two_sum.cpp)
add_executable(01_two_sum ${01_two_sum_SRC})

# 02_valid_palindrome.cpp
set(02_valid_palindrome_SRC 02_valid_palindrome.cpp)
add_executable(02_valid_palindrome ${02_valid_palindrome_SRC})

# 03_sentence_reverse.cpp
set(03_sentence_reverse_SRC 03_sentence_reverse.cpp)
add_executable(03_sentence_reverse ${03_sentence_reverse_SRC})
