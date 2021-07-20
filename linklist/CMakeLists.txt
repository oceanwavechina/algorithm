project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# common_node_in_linklist.cpp
set(common_node_in_linklist_SRC common_node_in_linklist.cpp)
add_executable(common_node_in_linklist ${common_node_in_linklist_SRC})

# delete_node_in_O1.cpp
set(delete_node_in_O1_SRC delete_node_in_O1.cpp)
add_executable(delete_node_in_O1 ${delete_node_in_O1_SRC})

# find_kth_to_tail.cpp
set(find_kth_to_tail_SRC find_kth_to_tail.cpp)
add_executable(find_kth_to_tail ${find_kth_to_tail_SRC})

# linklist_reverse.cpp
set(linklist_reverse_SRC linklist_reverse.cpp)
add_executable(linklist_reverse ${linklist_reverse_SRC})

# merge_k_sorted_linklist.cpp
set(merge_k_sorted_linklist_SRC merge_k_sorted_linklist.cpp)
add_executable(merge_k_sorted_linklist ${merge_k_sorted_linklist_SRC})

# merge_sorted_linklist.cpp
set(merge_sorted_linklist_SRC merge_sorted_linklist.cpp)
add_executable(merge_sorted_linklist ${merge_sorted_linklist_SRC})

# delete_node_in_O1.cpp
set(delete_node_in_O1_SRC delete_node_in_O1.cpp)
add_executable(delete_node_in_O1 ${delete_node_in_O1_SRC})

endif(0)

# is_palindrome.cpp
set(is_palindrome_SRC is_palindrome.cpp)
add_executable(is_palindrome ${is_palindrome_SRC})

# linklist_reverse.cpp
set(linklist_reverse_SRC linklist_reverse.cpp)
add_executable(linklist_reverse ${linklist_reverse_SRC})