project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

if(0)

# binary_search
set(binary_search_SRC binary_search.cpp)
add_executable(binary_search ${binary_search_SRC})
#target_link_libraries(binary_search m)

# search_in_rotated_sorted_array.cpp
set(search_in_rotated_sorted_array_SRC search_in_rotated_sorted_array.cpp)
add_executable(search_in_rotated_sorted_array ${search_in_rotated_sorted_array_SRC})


endif(0)

