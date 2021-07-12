project(AlgorithmBOX_String)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# Aho-Corasick_automation.cpp
set(Aho-Corasick_automation_SRC Aho-Corasick_automation.cpp)
add_executable(Aho-Corasick_automation ${Aho-Corasick_automation_SRC})

# KMP.cpp
set(KMP_SRC KMP.cpp)
add_executable(KMP ${KMP_SRC})

# longest_unrepeat_substring.cpp
set(longest_unrepeat_substring_SRC longest_unrepeat_substring.cpp)
add_executable(longest_unrepeat_substring ${longest_unrepeat_substring_SRC})

# sentence_reverse.cpp
set(sentence_reverse_SRC sentence_reverse.cpp)
add_executable(sentence_reverse ${sentence_reverse_SRC})

# string_reverse.cpp
set(string_reverse_SRC string_reverse.cpp)
add_executable(string_reverse ${string_reverse_SRC})

# string_rotate.cpp
set(string_rotate_SRC string_rotate.cpp)
add_executable(string_rotate ${string_rotate_SRC})

# strstr.cpp
set(strstr_SRC strstr.cpp)
add_executable(strstr ${strstr_SRC})

# valid_palindrome.cpp
set(valid_palindrome_SRC valid_palindrome.cpp)
add_executable(valid_palindrome ${valid_palindrome_SRC})

# find_all_legal_IPs.cpp
set(find_all_legal_IPs_SRC find_all_legal_IPs.cpp)
add_executable(find_all_legal_IPs ${find_all_legal_IPs_SRC})

# my_atoi.cpp
set(my_atoi_SRC my_atoi.cpp)
add_executable(my_atoi ${my_atoi_SRC})

# my_itoa.cpp
set(my_itoa_SRC my_itoa.cpp)
add_executable(my_itoa ${my_itoa_SRC})


endif(0)

# first_none_repeat_charactor.cpp
set(first_none_repeat_charactor_SRC first_none_repeat_charactor.cpp)
add_executable(first_none_repeat_charactor ${first_none_repeat_charactor_SRC})




