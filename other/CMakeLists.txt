project(AlgorithmBOX_Other)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# memory_pool.cpp
set(memory_pool_SRC memory_pool.cpp)
add_executable(memory_pool ${memory_pool_SRC})

# LRU_cache.cpp
set(LRU_cache_SRC LRU_cache.cpp)
add_executable(LRU_cache ${LRU_cache_SRC})

# simplify_path.cpp
set(simplify_path_SRC simplify_path.cpp)
add_executable(simplify_path ${simplify_path_SRC})

# valid_parentheses.cpp
set(valid_parentheses_SRC valid_parentheses.cpp)
add_executable(valid_parentheses ${valid_parentheses_SRC})

# print_Z_pattern.cpp
set(print_Z_pattern_SRC print_Z_pattern.cpp)
add_executable(print_Z_pattern ${print_Z_pattern_SRC})

# make_team.cpp
set(make_team_SRC make_team.cpp)
add_executable(make_team ${make_team_SRC})

# next_permutation.cpp
set(next_permutation_SRC next_permutation.cpp)
add_executable(next_permutation ${next_permutation_SRC})

# stack_with_min.cpp
set(stack_with_min_SRC stack_with_min.cpp)
add_executable(stack_with_min ${stack_with_min_SRC})

# top_k_numbers.cpp
set(top_k_numbers_SRC top_k_numbers.cpp)
add_executable(top_k_numbers ${top_k_numbers_SRC})

# number_of_1.cpp
set(number_of_1_SRC number_of_1.cpp)
add_executable(number_of_1 ${number_of_1_SRC})

# queue_by_two_stacks.cpp
set(queue_by_two_stacks_SRC queue_by_two_stacks.cpp)
add_executable(queue_by_two_stacks ${queue_by_two_stacks_SRC})

# intervals_merge.cpp
set(intervals_merge_SRC intervals_merge.cpp)
add_executable(intervals_merge ${intervals_merge_SRC})

endif(0)


# intervals_insert.cpp
set(intervals_insert_SRC intervals_insert.cpp)
add_executable(intervals_insert ${intervals_insert_SRC})



