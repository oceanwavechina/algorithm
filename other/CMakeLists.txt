project(AlgorithmBOX_Other)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

#if(0)

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

# none_make_team.cpp
set(none_make_team_SRC none_make_team.cpp)
add_executable(none_make_team ${none_make_team_SRC})

#endif(0)
