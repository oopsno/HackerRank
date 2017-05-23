project(leetcode/domains/data-structures/trees)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name src)
    list(APPEND SOURCES ${src})
endmacro()

add_solution("Tree: Preorder Traversal"       tree.cpp)
add_solution("Tree: Postorder Traversal"      tree.cpp)
add_solution("Tree: Inorder Traversal"        tree.cpp)
add_solution("Tree: Height of a Binary Tree"  tree.cpp)
add_solution("Tree: Top View"                 tree.cpp)
add_solution("Tree: Level Order Traversal"    tree.cpp)
add_solution("Binary Search Tree: Insertion"  tree.cpp)

list(REMOVE_DUPLICATES SOURCES)
add_library(domain-ds-trees ${SOURCES})
add_executable(domain-ds-trees-debug debug.cpp)
target_link_libraries(domain-ds-trees-debug domain-ds-trees)
