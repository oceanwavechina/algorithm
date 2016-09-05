project(Algorithm)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

# sort_using_libraries.cpp
set(sort_using_libraries_SRC sort_using_libraries.cpp)
add_executable(sort_using_libraries ${sort_using_libraries_SRC})

# bitmap_sort.cpp
set(bitmap_sort_SRC bitmap_sort.cpp)
add_executable(bitmap_sort ${bitmap_sort_SRC})

# bitmap_sort_STL.cpp
set(bitmap_sort_STL_SRC bitmap_sort_STL.cpp)
add_executable(bitmap_sort_STL ${bitmap_sort_STL_SRC})

# bitmap_sort_with_count.cpp
set(bitmap_sort_with_count_SRC bitmap_sort_with_count.cpp)
add_executable(bitmap_sort_with_count ${bitmap_sort_with_count_SRC})
