target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPPacket.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPPacket.cpp
)
