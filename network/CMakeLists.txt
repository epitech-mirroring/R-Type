add_library(Rtype-network STATIC)
add_library(rtype::network ALIAS Rtype-network)
target_link_libraries(Rtype-network
        PUBLIC
        asio::asio
        stellar-forge-common::stellar-forge-common
)

target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/server/ISessionServer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/client/ISessionClient.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/IInternalMessage.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/IInternalMessageClient.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/ClientConnected.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/ClientDisconnected.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/ServerStarted.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/Server.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/client/Client.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/client/Client.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/Server.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/ClientConnected.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/ClientDisconnected.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server/InternalMessage/ServerStarted.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/NetworkException.cpp
)
