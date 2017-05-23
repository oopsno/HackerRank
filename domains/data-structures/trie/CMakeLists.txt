project(leetcode/domains/data-structures/trie)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name src)
    get_filename_component(BASENAME ${src} NAME_WE)
    add_executable(domain-ds-trie-${BASENAME} ${src})
endmacro()

add_solution("Contacts"       ../../../tutorials/cracking-the-coding-interview-challenges/tries-contacts.cpp)
add_solution("No Prefix Set"  no-prefix-set.cpp)
