project(DataStructures)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++17")

if(0)
###########  WEEK 2  ###########
# heaps_sort.cpp
set(heaps_sort_SRC heaps_sort.cpp)
add_executable(heaps_sort ${heaps_sort_SRC})

# heaps_sort_zero_based.cpp
set(heaps_sort_zero_based_SRC heaps_sort_zero_based.cpp)
add_executable(heaps_sort_zero_based ${heaps_sort_zero_based_SRC})

# disjoin_set.cpp
set(disjoin_set_SRC disjoin_set.cpp)
add_executable(disjoin_set ${disjoin_set_SRC})


# disjoin_set_path_compression.cpp
set(disjoin_set_path_compression_SRC disjoin_set_path_compression.cpp)
add_executable(disjoin_set_path_compression ${disjoin_set_path_compression_SRC})

# binary_search_tree.cpp
set(binary_search_tree_SRC binary_search_tree.cpp)
add_executable(binary_search_tree ${binary_search_tree_SRC})


# binary_search_tree_2.cpp
set(binary_search_tree_2_SRC binary_search_tree_2.cpp)
add_executable(binary_search_tree_2 ${binary_search_tree_2_SRC})


# hash_table.cpp
set(hash_table_SRC hash_table.cpp)
add_executable(hash_table ${hash_table_SRC})

# B_tree.cpp
set(B_tree_SRC B_tree.cpp)
add_executable(B_tree ${B_tree_SRC})

endif(0)


# hash_table.cpp
set(hash_table_SRC hash_table.cpp)
add_executable(hash_table ${hash_table_SRC})