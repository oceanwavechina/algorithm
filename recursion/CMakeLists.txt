project(Algorithm_Recursive)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

#if(0)

# FibRecurs.cpp
set(FibRecurs_SRC FibRecurs.cpp)
add_executable(FibRecurs ${FibRecurs_SRC})

# recursive_linear_search.cpp
set(recursive_linear_search_SRC recursive_linear_search.cpp)
add_executable(recursive_linear_search ${recursive_linear_search_SRC})

# GCD.cpp
set(GCD_SRC GCD.cpp)
add_executable(GCD ${GCD_SRC})

# max_pairwise_product
set(max_pairwise_product_SRC max_pairwise_product.cpp)
add_executable(max_pairwise_product ${max_pairwise_product_SRC})

#endif(0)
