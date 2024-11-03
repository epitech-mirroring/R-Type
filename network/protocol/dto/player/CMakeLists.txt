target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerActionEnum.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/APlayerDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerActionStartDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerActionStopDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerActionStartDTO.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/APlayerDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerActionStartDTO.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerActionStopDTO.cpp
)
