project(AlgorithmBOX_DP)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

#if(0)

# PointsCoverSorted.cpp
set(PointsCoverSorted_SRC PointsCoverSorted.cpp)
add_executable(PointsCoverSorted ${PointsCoverSorted_SRC})

# LargestNumber.cpp
set(LargestNumber_SRC LargestNumber.cpp)
add_executable(LargestNumber ${LargestNumber_SRC})

# fractional_knapsack.cpp
set(fractional_knapsack_SRC fractional_knapsack.cpp)
add_executable(fractional_knapsack ${fractional_knapsack_SRC})

# MinRefills.cpp
set(MinRefills_SRC MinRefills.cpp)
add_executable(MinRefills ${MinRefills_SRC})

#endif(0)





