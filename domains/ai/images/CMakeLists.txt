project(leetcode/domains/ai/images)
cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

macro(add_solution name src)
    get_filename_component(BASENAME ${src} NAME_WE)
    add_executable(domain-ai-iamges-${BASENAME} ${src})
endmacro()

add_solution("Digital Camera Autodetect: Day or Night"     day-or-night.cpp)
