cmake_minimum_required(VERSION 3.7)
project(experience)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

add_executable(experience
        main.cpp
        global.h
        Solution.h
        ccf.h
        methods/tree.cpp
        methods/tree.h)

add_executable(test
        tests/test.cpp
        tests/structtest.cpp
        tests/structtest.h
        global.h)
