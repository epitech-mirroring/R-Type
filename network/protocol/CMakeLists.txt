target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/IDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/IDTOEncoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/IDTODecoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTODecoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTOEncoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTORegistry.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTOException.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityTypeEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/AEntityDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityPositionDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityCreationDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityDeletionDTO.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/PlayerActionEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/APlayerDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/PlayerActionStartDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/PlayerActionStopDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/PlayerActionStartDTO.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/ATCPDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/TCPSendIdDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/MessageTypeEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/TCPCreateUDPEndpointDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/TCPMessageDTO.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/conversion/BinaryVector.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/packet/TCPPacket.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTORegistry.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTODecoder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTOEncoder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/DTOException.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/AEntityDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityPositionDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityCreationDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/entity/EntityDeletionDTO.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/APlayerDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/PlayerActionStartDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/player/PlayerActionStopDTO.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/ATCPDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/TCPSendIdDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/TCPCreateUDPEndpointDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dto/tcp/TCPMessageDTO.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/packet/TCPPacket.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/conversion/BinaryVector.cpp
)
