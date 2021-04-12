project(AlgorithmBOX_HASH)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# bloom_filter.cpp
set(bloom_filter_SRC bloom_filter.cpp)
add_executable(bloom_filter ${bloom_filter_SRC})


# consistent_hash_with_virtual_nodes.cpp
set(consistent_hash_with_virtual_nodes_SRC consistent_hash_with_virtual_nodes.cpp)
add_executable(consistent_hash_with_virtual_nodes ${consistent_hash_with_virtual_nodes_SRC})


# consistent_hash_jump_consistent_hash.cpp
set(consistent_hash_jump_consistent_hash_SRC consistent_hash_jump_consistent_hash.cpp)
add_executable(consistent_hash_jump_consistent_hash ${consistent_hash_jump_consistent_hash_SRC})


# hash_table_open_addressing.cpp
set(hash_table_open_addressing_SRC hash_table_open_addressing.cpp)
add_executable(hash_table_open_addressing ${hash_table_open_addressing_SRC})


# counter_min_sketch.cpp
set(counter_min_sketch_SRC counter_min_sketch.cpp)
add_executable(counter_min_sketch ${counter_min_sketch_SRC})

endif(0)


# hash_table_open_addressing.cpp
set(hash_table_open_addressing_SRC hash_table_open_addressing.cpp)
add_executable(hash_table_open_addressing ${hash_table_open_addressing_SRC})
