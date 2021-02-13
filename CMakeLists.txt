cmake_minimum_required(VERSION 3.17)
project(experience)

set(CMAKE_CXX_STANDARD 11)

add_executable(experience
        main.cpp
        calgorithm.h
        global.cpp
        global.h
        structtest.cpp
        structtest.h
        test.cpp
        Solution.h)

#add_executable(client
#        client.cpp)
#
#add_executable(server
#        server.cpp)