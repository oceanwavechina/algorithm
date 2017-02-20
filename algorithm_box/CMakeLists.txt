project(AlgorithmBOX)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++14")

if(0)
# sum_of_three_numbers.cpp
set(sum_of_three_numbers_SRC sum_of_three_numbers.cpp)
add_executable(sum_of_three_numbers ${sum_of_three_numbers_SRC})

# string_rotate.cpp
set(string_rotate_SRC string_rotate.cpp)
add_executable(string_rotate ${string_rotate_SRC})


# string_reverse.cpp
set(string_reverse_SRC string_reverse.cpp)
add_executable(string_reverse ${string_reverse_SRC})


# problility.cpp
set(problility_SRC problility.cpp)
add_executable(problility ${problility_SRC})


# straight_insertion_sort.cpp
set(straight_insertion_sort_SRC straight_insertion_sort.cpp)
add_executable(straight_insertion_sort ${straight_insertion_sort_SRC})

# selection_sort.cpp
set(selection_sort_SRC selection_sort.cpp)
add_executable(selection_sort ${selection_sort_SRC})

# BinaryTree_2_LinkList.cpp
set(BinaryTree_2_LinkList_SRC BinaryTree_2_LinkList.cpp)
add_executable(BinaryTree_2_LinkList ${BinaryTree_2_LinkList_SRC})

# BinaryTree_2_LinkList_with_queue.cpp
set(BinaryTree_2_LinkList_with_queue_SRC BinaryTree_2_LinkList_with_queue.cpp)
add_executable(BinaryTree_2_LinkList_with_queue ${BinaryTree_2_LinkList_with_queue_SRC})

# radix_convert.cpp
set(radix_convert_SRC radix_convert.cpp)
add_executable(radix_convert ${radix_convert_SRC})

# linklist_reverse.cpp
set(linklist_reverse_SRC linklist_reverse.cpp)
add_executable(linklist_reverse ${linklist_reverse_SRC})

# BinaryTree_Traversing.cpp
set(BinaryTree_Traversing_SRC BinaryTree_Traversing.cpp)
add_executable(BinaryTree_Traversing ${BinaryTree_Traversing_SRC})

# memory_pool.cpp
set(memory_pool_SRC memory_pool.cpp)
add_executable(memory_pool ${memory_pool_SRC})

# common_node_in_linklist.cpp
set(common_node_in_linklist_SRC common_node_in_linklist.cpp)
add_executable(common_node_in_linklist ${common_node_in_linklist_SRC})

# up_the_steps.cpp
set(up_the_steps_SRC up_the_steps.cpp)
add_executable(up_the_steps ${up_the_steps_SRC})

endif(0)

# longest_unrepeat_substring.cpp
set(longest_unrepeat_substring_SRC longest_unrepeat_substring.cpp)
add_executable(longest_unrepeat_substring ${longest_unrepeat_substring_SRC})
