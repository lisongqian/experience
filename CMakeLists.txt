cmake_minimum_required(VERSION 3.7)
project(experience)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)

add_executable(experience
        main.cpp
        global.cpp
        global.h
        Solution.h)

#add_executable(client
#        client.cpp)
#
#add_executable(server
#        server.cpp)