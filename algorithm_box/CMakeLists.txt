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

# BinaryTree_output_by_level.cpp
set(BinaryTree_output_by_level_SRC BinaryTree_output_by_level.cpp)
add_executable(BinaryTree_output_by_level ${BinaryTree_output_by_level_SRC})

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

# longest_unrepeat_substring.cpp
set(longest_unrepeat_substring_SRC longest_unrepeat_substring.cpp)
add_executable(longest_unrepeat_substring ${longest_unrepeat_substring_SRC})

# tree_depth.cpp
set(tree_depth_SRC tree_depth.cpp)
add_executable(tree_depth ${tree_depth_SRC})

# 01_two_sum.cpp
set(01_two_sum_SRC 01_two_sum.cpp)
add_executable(01_two_sum ${01_two_sum_SRC})

# 02_valid_palindrome.cpp
set(02_valid_palindrome_SRC 02_valid_palindrome.cpp)
add_executable(02_valid_palindrome ${02_valid_palindrome_SRC})

# 03_sentence_reverse.cpp
set(03_sentence_reverse_SRC 03_sentence_reverse.cpp)
add_executable(03_sentence_reverse ${03_sentence_reverse_SRC})

# 04_reverse_integer.cpp
set(04_reverse_integer_SRC 04_reverse_integer.cpp)
add_executable(04_reverse_integer ${04_reverse_integer_SRC})

# binary_tree_maximum_path_sum.cpp
set(binary_tree_maximum_path_sum_SRC binary_tree_maximum_path_sum.cpp)
add_executable(binary_tree_maximum_path_sum ${binary_tree_maximum_path_sum_SRC})

# 05_strstr.cpp
set(05_strstr_SRC 05_strstr.cpp)
add_executable(05_strstr ${05_strstr_SRC})

# selection_sort.cpp
set(selection_sort_SRC selection_sort.cpp)
add_executable(selection_sort ${selection_sort_SRC})

# longest_unrepeat_substring.cpp
set(longest_unrepeat_substring_SRC longest_unrepeat_substring.cpp)
add_executable(longest_unrepeat_substring ${longest_unrepeat_substring_SRC})

# find_kth_to_tail.cpp
set(find_kth_to_tail_SRC find_kth_to_tail.cpp)
add_executable(find_kth_to_tail ${find_kth_to_tail_SRC})

# remove_duplicates.cpp
set(remove_duplicates_SRC remove_duplicates.cpp)
add_executable(remove_duplicates ${remove_duplicates_SRC})

# search_in_rotated_sorted_array.cpp
set(search_in_rotated_sorted_array_SRC search_in_rotated_sorted_array.cpp)
add_executable(search_in_rotated_sorted_array ${search_in_rotated_sorted_array_SRC})

# binary_tree_maximum_path_sum.cpp
set(binary_tree_maximum_path_sum_SRC binary_tree_maximum_path_sum.cpp)
add_executable(binary_tree_maximum_path_sum ${binary_tree_maximum_path_sum_SRC})

# longet_common_subsequence.cpp
set(longet_common_subsequence_SRC longet_common_subsequence.cpp)
add_executable(longet_common_subsequence ${longet_common_subsequence_SRC})

# find_greatest_sum_of_subarray.cpp
set(find_greatest_sum_of_subarray_SRC find_greatest_sum_of_subarray.cpp)
add_executable(find_greatest_sum_of_subarray ${find_greatest_sum_of_subarray_SRC})

# LRU_cache.cpp
set(LRU_cache_SRC LRU_cache.cpp)
add_executable(LRU_cache ${LRU_cache_SRC})

# simplify_path.cpp
set(simplify_path_SRC simplify_path.cpp)
add_executable(simplify_path ${simplify_path_SRC})

# factorial_zero_cnt.cpp
set(factorial_zero_cnt_SRC factorial_zero_cnt.cpp)
add_executable(factorial_zero_cnt ${factorial_zero_cnt_SRC})

# find_all_legal_IPs.cpp
set(find_all_legal_IPs_SRC find_all_legal_IPs.cpp)
add_executable(find_all_legal_IPs ${find_all_legal_IPs_SRC})

# bloom_filter.cpp
set(bloom_filter_SRC bloom_filter.cpp)
add_executable(bloom_filter ${bloom_filter_SRC})

# find_in_sorted_2D_array.cpp
set(find_in_sorted_2D_array_SRC find_in_sorted_2D_array.cpp)
add_executable(find_in_sorted_2D_array ${find_in_sorted_2D_array_SRC})

# single_number.cpp
set(single_number_SRC single_number.cpp)
add_executable(single_number ${single_number_SRC})


endif(0)


# merge_sorted_linklist.cpp
set(merge_sorted_linklist_SRC merge_sorted_linklist.cpp)
add_executable(merge_sorted_linklist ${merge_sorted_linklist_SRC})


