target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/GameSpeedEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GameSpeedDTO.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/GameSpeedDTO.cpp
)
