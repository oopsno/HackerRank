project(leetcode/tutorials/cracking-the-coding-interview-challenges)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name code)
    if (${ARGC} GREATER 2)
        list(APPEND CTCI_HEADLESS_CODES ${code})
    else()
        string(REPLACE ".cpp" "" TARGET_NAME ${code})
        add_executable(${TARGET_NAME} ${code})
    endif()
endmacro()

# DATA STRUCTURES
add_solution("Arrays: Left Rotation"                array-left-rotation.cpp)
add_solution("Hash Tables: Ransom Note"             hash-ransom-note.cpp)
add_solution("Linked Lists: Detect a Cycle"         linked-list-detect-cycle.cpp)
add_solution("Stacks: Balanced Brackets"            stacks-balanced-brackets.cpp)
add_solution("Queues: A Tale of Two Stacks"         queues-a-tale-of-two-stacks.cpp)
add_solution("Trees: Is This a Binary Search Tree?" is-binary-search-tree.cpp HEADLESS)
add_solution("Tries: Contacts"                      tries-contacts.cpp)

# ALGORITHMS
add_solution("Sorting: Bubble Sort"                 sorting-bubble-sort.cpp)
add_solution("Sorting: Comparator"                  sorting-comparator.cpp)

# TECHNIQUES/CONCEPTS
add_solution("Recursion: Fibonacci Numbers"         recursion-fibonacci-numbers.cpp)
add_solution("Recursion: Davis' Staircase"          recursion-davis-staircase.cpp)
add_solution("Bit Manipulation: Lonely Integer"     bit-lonely-int.cpp)

add_library(ctci ${CTCI_HEADLESS_CODES})
