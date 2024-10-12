cmake_minimum_required(VERSION 3.29)

project(R-Type-Reborn
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(includes)

link_directories(libs)

find_package(asio REQUIRED)

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(network)

include_directories(network)
#add_subdirectory(tests)
