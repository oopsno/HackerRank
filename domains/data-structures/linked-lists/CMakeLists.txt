project(leetcode/domains/data-structures/linked-lists)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name src)
    list(APPEND SOURCES ${src})
endmacro()

add_solution("Print the Elements of a Linked List"                    print.cpp)
add_solution("Insert a Node at the Tail of a Linked List"             insert-at-tail.cpp)
add_solution("Insert a Node at the Head of a Linked List"             insert-at-head.cpp)
add_solution("Insert a node at a specific position in a linked list"  insert-at.cpp)
add_solution("Delete a Node"                                          delete.cpp)
add_solution("Print in Reverse"                                       reverse-print.cpp)
add_solution("Reverse a linked list"                                  reverse.cpp)
add_solution("Compare two linked lists"                               compare.cpp)
add_solution("Merge two sorted linked lists"                          merge.cpp)
add_solution("Get Node Value"                                         get-value.cpp)
add_solution("Delete duplicate-value nodes from a sorted linked list" remove-dup.cpp)
add_solution("Cycle Detection"                                        has-cycle.cpp)
add_solution("Find Merge Point of Two Lists"                          find-merge-point.cpp)
add_solution("Inserting a Node Into a Sorted Doubly Linked List"      doubly-insert.cpp)
add_solution("Reverse a doubly linked list"                           doubly-reverse.cpp)

add_library(domain-ds-linked-lists ${SOURCES} node.cpp)
add_executable(domain-ds-linked-lists-debug debug.cpp)
target_link_libraries(domain-ds-linked-lists-debug domain-ds-linked-lists)
