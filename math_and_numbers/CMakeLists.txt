project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# factorial_zero_cnt
set(factorial_zero_cnt_SRC factorial_zero_cnt.cpp)
add_executable(factorial_zero_cnt ${factorial_zero_cnt_SRC})

#  fast_invert_sqrt
set(fast_invert_sqrt_SRC fast_invert_sqrt.cpp)
add_executable(fast_invert_sqrt ${fast_invert_sqrt_SRC})

#  find_median
set(find_median_SRC find_median.cpp)
add_executable(find_median ${find_median_SRC})

#  find_more_than_half_number
set(find_more_than_half_number_SRC find_more_than_half_number.cpp)
add_executable(find_more_than_half_number ${find_more_than_half_number_SRC})

#  find_the_difference
set(find_the_difference_SRC find_the_difference.cpp)
add_executable(find_the_difference ${find_the_difference_SRC})

#  maximum_after_swap
set(maximum_after_swap_SRC maximum_after_swap.cpp)
add_executable(maximum_after_swap ${maximum_after_swap_SRC})

#  polynomial_multiplication
set(polynomial_multiplication_SRC polynomial_multiplication.cpp)
add_executable(polynomial_multiplication ${polynomial_multiplication_SRC})

#  problility
set(problility_SRC problility.cpp)
add_executable(problility ${problility_SRC})

#  radix_convert
set(radix_convert_SRC radix_convert.cpp)
add_executable(radix_convert ${radix_convert_SRC})

#  reverse_integer
set(reverse_integer_SRC reverse_integer.cpp)
add_executable(reverse_integer ${reverse_integer_SRC})

#  single_number
set(single_number_SRC single_number.cpp)
add_executable(single_number ${single_number_SRC})

endif(0)

#  find_more_than_half_number
set(find_more_than_half_number_SRC find_more_than_half_number.cpp)
add_executable(find_more_than_half_number ${find_more_than_half_number_SRC})

