cmake_minimum_required(VERSION 3.5)
add_library(Rtype-network STATIC)
add_library(rtype::network ALIAS Rtype-network)
target_link_libraries(Rtype-network
        PUBLIC
        asio::asio
)

target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/server/Server.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/client/Client.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/client/Client.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/Server.cpp
)
