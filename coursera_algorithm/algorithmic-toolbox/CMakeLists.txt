project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

###########  WEEK 2  ###########
# A plus B
set(APlusB_SRC APlusB.cpp)
add_executable(a_plus_b ${APlusB_SRC})
#target_link_libraries(a_plus_b m)

# 𝚖𝚊𝚡_𝚙𝚊𝚒𝚛𝚠𝚒𝚜𝚎_𝚙𝚛𝚘𝚍𝚞𝚌𝚝
set(max_pairwise_product_SRC max_pairwise_product.cpp)
add_executable(max_pairwise_product ${max_pairwise_product_SRC})

# cpp_stress_test
set(cpp_stress_test_SRC cpp_stress_test.cpp)
add_executable(cpp_stress_test ${cpp_stress_test_SRC})

# fibrecurs
set(FibRecurs_SRC FibRecurs.cpp)
add_executable(FibRecurs ${FibRecurs_SRC})

# GCD.cpp
set(GCD_SRC GCD.cpp)
add_executable(GCD ${GCD_SRC})


###########  WEEK 3  ###########
# LargestNumber.cpp
set(LargestNumber_SRC LargestNumber.cpp)
add_executable(LargestNumber ${LargestNumber_SRC})

# MinRefills.cpp
set(MinRefills_SRC MinRefills.cpp)
add_executable(MinRefills ${MinRefills_SRC})

# PointsCoverSorted.cpp
set(PointsCoverSorted_SRC PointsCoverSorted.cpp)
add_executable(PointsCoverSorted ${PointsCoverSorted_SRC})

# fractional_knapsack.cpp
set(fractional_knapsack_SRC fractional_knapsack.cpp)
add_executable(fractional_knapsack ${fractional_knapsack_SRC})


###########  WEEK 4  ###########
# recursive_linear_search.cpp
set(recursive_linear_search_SRC recursive_linear_search.cpp)
add_executable(recursive_linear_search ${recursive_linear_search_SRC})

# binary_search.cpp
set(binary_search_SRC binary_search.cpp)
add_executable(binary_search ${binary_search_SRC})

# polynomial_multiplication.cpp
set(polynomial_multiplication_SRC polynomial_multiplication.cpp)
add_executable(polynomial_multiplication ${polynomial_multiplication_SRC})

# selection_sort.cpp
set(selection_sort_SRC selection_sort.cpp)
add_executable(selection_sort ${selection_sort_SRC})

# merge_sort.cpp
set(merge_sort_SRC merge_sort.cpp)
add_executable(merge_sort ${merge_sort_SRC})

# quick_sort.cpp
set(quick_sort_SRC quick_sort.cpp)
add_executable(quick_sort ${quick_sort_SRC})
