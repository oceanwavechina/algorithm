project(sortingandsearching)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++14")

if(0)

# 1_selection_sort.cpp
set(1_selection_sort_SRC 1_selection_sort.cpp)
add_executable(1_selection_sort ${1_selection_sort_SRC})

# 2_bubble_sort.cpp
set(2_bubble_sort_SRC 2_bubble_sort.cpp)
add_executable(2_bubble_sort ${2_bubble_sort_SRC})

# 3.2_quick_sort_Lomuto_partition.cpp
set(3.2_quick_sort_Lomuto_partition_SRC 3.2_quick_sort_Lomuto_partition.cpp)
add_executable(3.2_quick_sort_Lomuto_partition ${3.2_quick_sort_Lomuto_partition_SRC})

# 3.2_quick_sort_Lomuto_partition.cpp
set(3.2_quick_sort_Lomuto_partition_SRC 3.2_quick_sort_Lomuto_partition.cpp)
add_executable(3.2_quick_sort_Lomuto_partition ${3.2_quick_sort_Lomuto_partition_SRC})


endif(0)


# 3.1_quick_sort_Hoare_partition.cpp
set(3.1_quick_sort_Hoare_partition_SRC 3.1_quick_sort_Hoare_partition.cpp)
add_executable(3.1_quick_sort_Hoare_partition ${3.1_quick_sort_Hoare_partition_SRC})



