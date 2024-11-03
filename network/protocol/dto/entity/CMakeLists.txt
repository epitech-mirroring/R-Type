target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityTypeEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AEntityDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityPositionDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityCreationDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityDeletionDTO.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/AEntityDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityPositionDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityCreationDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityDeletionDTO.cpp
)
