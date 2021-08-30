project(AlgorithmBOX_BinaryTree)
cmake_minimum_required(VERSION 3.6)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2 -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -g -std=c++14")

if(0)

# binarytree_2_LinkList.cpp
set(binarytree_2_LinkList_SRC binarytree_2_LinkList.cpp)
add_executable(binarytree_2_LinkList ${binarytree_2_LinkList_SRC})

# binarytree_depth.cpp
set(binarytree_depth_SRC binarytree_depth.cpp)
add_executable(binarytree_depth ${binarytree_depth_SRC})

# binarytree_diameter.cpp
set(binarytree_diameter_SRC binarytree_diameter.cpp)
add_executable(binarytree_diameter ${binarytree_diameter_SRC})

# binarytree_traversing.cpp
set(binarytree_traversing_SRC binarytree_traversing.cpp)
add_executable(binarytree_traversing ${binarytree_traversing_SRC})

# count_complete_tree_nodes.cpp
set(count_complete_tree_nodes_SRC count_complete_tree_nodes.cpp)
add_executable(count_complete_tree_nodes ${count_complete_tree_nodes_SRC})

# maximum_path_sum.cpp
set(maximum_path_sum_SRC maximum_path_sum.cpp)
add_executable(maximum_path_sum ${maximum_path_sum_SRC})

# output_binarytree_by_level.cpp
set(output_binarytree_by_level_SRC output_binarytree_by_level.cpp)
add_executable(output_binarytree_by_level ${output_binarytree_by_level_SRC})

# lowest_common_ancestor_of_BST.cpp
set(lowest_common_ancestor_of_BST_SRC lowest_common_ancestor_of_BST.cpp)
add_executable(lowest_common_ancestor_of_BST ${lowest_common_ancestor_of_BST_SRC})

# mirror_tree.cpp
set(mirror_tree_SRC mirror_tree.cpp)
add_executable(mirror_tree ${mirror_tree_SRC})

# find_node_with_multi_parent.cpp
set(find_node_with_multi_parent_SRC find_node_with_multi_parent.cpp)
add_executable(find_node_with_multi_parent ${find_node_with_multi_parent_SRC})

# lowest_common_ancestor_with_parent_pointer.cpp
set(lowest_common_ancestor_with_parent_pointer_SRC lowest_common_ancestor_with_parent_pointer.cpp)
add_executable(lowest_common_ancestor_with_parent_pointer ${lowest_common_ancestor_with_parent_pointer_SRC})

# lowest_common_acestor_of_trivial_tree_recursion.cpp
set(lowest_common_acestor_of_trivial_tree_recursion_SRC lowest_common_acestor_of_trivial_tree_recursion.cpp)
add_executable(lowest_common_acestor_of_trivial_tree_recursion ${lowest_common_acestor_of_trivial_tree_recursion_SRC})

# lowest_common_acestor_of_trivial_tree_stack.cpp
set(lowest_common_acestor_of_trivial_tree_stack_SRC lowest_common_acestor_of_trivial_tree_stack.cpp)
add_executable(lowest_common_acestor_of_trivial_tree_stack ${lowest_common_acestor_of_trivial_tree_stack_SRC})

endif(0)

# lowest_common_acestor_of_trivial_tree_recursion.cpp
set(lowest_common_acestor_of_trivial_tree_recursion_SRC lowest_common_acestor_of_trivial_tree_recursion.cpp)
add_executable(lowest_common_acestor_of_trivial_tree_recursion ${lowest_common_acestor_of_trivial_tree_recursion_SRC})
