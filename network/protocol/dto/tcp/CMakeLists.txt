target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ATCPDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPSendIdDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MessageTypeEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPCreateUDPEndpointDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPMessageDTO.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ATCPDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPSendIdDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPCreateUDPEndpointDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TCPMessageDTO.cpp
)
