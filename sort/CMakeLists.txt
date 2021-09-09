project(Algorithm_Recursive)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")

if(0)

# 1_selection_sort.cpp
set(1_selection_sort_SRC 1_selection_sort.cpp)
add_executable(1_selection_sort ${1_selection_sort_SRC})

# 2_bubble_sort.cpp
set(2_bubble_sort_SRC 2_bubble_sort.cpp)
add_executable(2_bubble_sort ${2_bubble_sort_SRC})

# 3.1_quick_sort_Hoare_partition.cpp
set(3.1_quick_sort_Hoare_partition_SRC 3.1_quick_sort_Hoare_partition.cpp)
add_executable(3.1_quick_sort_Hoare_partition ${3.1_quick_sort_Hoare_partition_SRC})

# 3.2_quick_sort_Lomuto_partition.cpp
set(3.2_quick_sort_Lomuto_partition_SRC 3.2_quick_sort_Lomuto_partition.cpp)
add_executable(3.2_quick_sort_Lomuto_partition ${3.2_quick_sort_Lomuto_partition_SRC})

# 3.4_quick_sort_optimazation.cpp
set(3.4_quick_sort_optimazation_SRC 3.4_quick_sort_optimazation.cpp)
add_executable(3.4_quick_sort_optimazation ${3.4_quick_sort_optimazation_SRC})

# bucket_sort.cpp
set(bucket_sort_SRC bucket_sort.cpp)
add_executable(bucket_sort ${bucket_sort_SRC})

# merge_sort.cpp
set(merge_sort_SRC merge_sort.cpp)
add_executable(merge_sort ${merge_sort_SRC})

# quick_sort.cpp
set(quick_sort_SRC quick_sort.cpp)
add_executable(quick_sort ${quick_sort_SRC})

# selection_sort.cpp
set(selection_sort_SRC selection_sort.cpp)
add_executable(selection_sort ${selection_sort_SRC})

# selection_sort2.cpp
set(selection_sort2_SRC selection_sort2.cpp)
add_executable(selection_sort2 ${selection_sort2_SRC})

# straight_insertion_sort.cpp
set(straight_insertion_sort_SRC straight_insertion_sort.cpp)
add_executable(straight_insertion_sort ${straight_insertion_sort_SRC})

endif(0)


# quick_sort.cpp
set(quick_sort_SRC quick_sort.cpp)
add_executable(quick_sort ${quick_sort_SRC})
