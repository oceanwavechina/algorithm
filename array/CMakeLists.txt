project(AlgorithmBOX)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

#if(0)

# find_all_subarray_with_0_sum.cpp
set(find_all_subarray_with_0_sum_SRC find_all_subarray_with_0_sum.cpp)
add_executable(find_all_subarray_with_0_sum ${find_all_subarray_with_0_sum_SRC})

# find_all_subarray_with_x_sum.cpp
set(find_all_subarray_with_x_sum_SRC find_all_subarray_with_x_sum.cpp)
add_executable(find_all_subarray_with_x_sum ${find_all_subarray_with_x_sum_SRC})

# find_greatest_sum_of_subarray.cpp
set(find_greatest_sum_of_subarray_SRC find_greatest_sum_of_subarray.cpp)
add_executable(find_greatest_sum_of_subarray ${find_greatest_sum_of_subarray_SRC})

# find_in_sorted_2D_array.cpp
set(find_in_sorted_2D_array_SRC find_in_sorted_2D_array.cpp)
add_executable(find_in_sorted_2D_array ${find_in_sorted_2D_array_SRC})

# search_in_rotated_sorted_array.cpp
set(search_in_rotated_sorted_array_SRC search_in_rotated_sorted_array.cpp)
add_executable(search_in_rotated_sorted_array ${search_in_rotated_sorted_array_SRC})

# subarray_with_given_sum.cpp
set(subarray_with_given_sum_SRC subarray_with_given_sum.cpp)
add_executable(subarray_with_given_sum ${subarray_with_given_sum_SRC})

# sum_of_three_numbers.cpp
set(sum_of_three_numbers_SRC sum_of_three_numbers.cpp)
add_executable(sum_of_three_numbers ${sum_of_three_numbers_SRC})

# two_sum.cpp
set(two_sum_SRC two_sum.cpp)
add_executable(two_sum ${two_sum_SRC})

# equilibrium_index.cpp
set(equilibrium_index_SRC equilibrium_index.cpp)
add_executable(equilibrium_index ${equilibrium_index_SRC})

# remove_duplicates.cpp
set(remove_duplicates_SRC remove_duplicates.cpp)
add_executable(remove_duplicates ${remove_duplicates_SRC})

# reverse_pair.cpp
set(reverse_pair_SRC reverse_pair.cpp)
add_executable(reverse_pair ${reverse_pair_SRC})

#endif(0)
