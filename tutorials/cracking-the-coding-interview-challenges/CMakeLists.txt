project(leetcode/tutorials/cracking-the-coding-interview-challenges)

macro(add_solution name code)
    if (${ARGC} GREATER 2)
        list(APPEND CTCI_HEADLESS_CODES ${code})
    else()
        string(REPLACE ".cpp" "" TARGET_NAME ${code})
        add_executable(${TARGET_NAME} ${code})
    endif()
endmacro()

add_solution("Arrays: Left Rotation"                array-left-rotation.cpp)
add_solution("Trees: Is This a Binary Search Tree?" is-binary-search-tree.cpp HEADLESS)
add_solution("Tries: Contacts"                      tries-contacts.cpp)
add_solution("Recursion: Fibonacci Numbers"         recursion-fibonacci-numbers.cpp)

add_library(ctci ${CTCI_HEADLESS_CODES})
