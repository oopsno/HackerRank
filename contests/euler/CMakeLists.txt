project(leetcode/contests/euler)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name id)
    add_executable(euler_${id} ${id}.cpp)
endmacro()

add_solution("Project Euler #1: Multiples of 3 and 5"   1)
add_solution("Project Euler #2: Even Fibonacci numbers" 2)
