cmake_minimum_required(VERSION 3.24)

project(Winsocket-Test
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(client client.cpp)
add_executable(server server.cpp)

