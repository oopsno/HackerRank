project(leetcode/domains/data-structures/arrays)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name src)
    string(REPLACE ".cpp" "" BASENAME ${src})
    add_executable(domain-ds-arrays-${BASENAME} ${src})
endmacro()

add_solution("Arrays - DS"    ds.cpp)
add_solution("2D Arrays - DS" 2d.cpp)
