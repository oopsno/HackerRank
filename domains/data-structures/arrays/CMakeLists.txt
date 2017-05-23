project(leetcode/domains/data-structures/arrays)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name src)
    get_filename_component(BASENAME ${src} NAME_WE)
    add_executable(domain-ds-arrays-${BASENAME} ${src})
endmacro()

add_solution("Arrays - DS"       ds.cpp)
add_solution("2D Arrays - DS"    2d.cpp)
add_solution("Dynamic Array"     dynamic.cpp)
add_solution("Left Rotation"     ../../../tutorials/cracking-the-coding-interview-challenges/array-left-rotation.cpp)
add_solution("Sparse Arrays"     sparse.cpp)
add_solution("Algorithmic Crush" crush.cpp)
