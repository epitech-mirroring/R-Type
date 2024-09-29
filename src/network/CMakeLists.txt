cmake_minimum_required(VERSION 3.5)
add_library(Rtype-network STATIC)
add_library(rtype::network ALIAS Rtype-network)
target_link_libraries(Rtype-network
        PRIVATE
        asio::asio
)

target_sources(Rtype-network
        PUBLIC
        server/server.hpp
        client/client.hpp
        PRIVATE
        client/client.cpp
)
