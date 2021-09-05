project(AlgorithmBOX)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# find_in_sorted_2D_array.cpp
set(find_in_sorted_2D_array_SRC find_in_sorted_2D_array.cpp)
add_executable(find_in_sorted_2D_array ${find_in_sorted_2D_array_SRC})

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

# remove_duplicates_allow_twice.cpp
set(remove_duplicates_allow_twice_SRC remove_duplicates_allow_twice.cpp)
add_executable(remove_duplicates_allow_twice ${remove_duplicates_allow_twice_SRC})

# find_repeat_twice.cpp
set(find_repeat_twice_SRC find_repeat_twice.cpp)
add_executable(find_repeat_twice ${find_repeat_twice_SRC})

# common_value_of_orderd_arrays.cpp
set(common_value_of_orderd_arrays_SRC common_value_of_orderd_arrays.cpp)
add_executable(common_value_of_orderd_arrays ${common_value_of_orderd_arrays_SRC})

# find_the_two_single_numbers.cpp
set(find_the_two_single_numbers_SRC find_the_two_single_numbers.cpp)
add_executable(find_the_two_single_numbers ${find_the_two_single_numbers_SRC})

# find_the_first_missing_number.cpp
set(find_the_first_missing_number_SRC find_the_first_missing_number.cpp)
add_executable(find_the_first_missing_number ${find_the_first_missing_number_SRC})

endif(0)


# partition_from_odd_even.cpp
set(partition_from_odd_even_SRC partition_from_odd_even.cpp)
add_executable(partition_from_odd_even ${partition_from_odd_even_SRC})


