cmake_minimum_required(VERSION 3.28)

project(R-Type-Reborn
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(includes)
include_directories(includes/StellarForge)
include_directories(network)


link_directories(libs)

find_package(asio REQUIRED)
find_package(glm REQUIRED)
find_package(SFML REQUIRED)

add_subdirectory(network)
add_subdirectory(client)
add_subdirectory(server)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/client)
