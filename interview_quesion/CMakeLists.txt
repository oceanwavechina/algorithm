project(InterviewQuestion)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++11")


# fork_test.cpp
set(fork_test_SRC fork_test.cpp)
add_executable(fork_test ${fork_test_SRC})


# class_derive_1.cpp
set(class_derive_1_SRC class_derive_1.cpp)
add_executable(class_derive_1 ${class_derive_1_SRC})

# class_derive_2.cpp
set(class_derive_2_SRC class_derive_2.cpp)
add_executable(class_derive_2 ${class_derive_2_SRC})

# cpp_01.cpp
set(cpp_01_SRC cpp_01.cpp)
add_executable(cpp_01 ${cpp_01_SRC})

# test_new.cpp
set(test_new_SRC test_new.cpp)
add_executable(test_new ${test_new_SRC})
