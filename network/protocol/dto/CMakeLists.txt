add_subdirectory(entity)
add_subdirectory(game)
add_subdirectory(player)
add_subdirectory(tcp)

target_sources(Rtype-network
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/IDTO.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IDTOEncoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/IDTODecoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTODecoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTOEncoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTORegistry.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTOException.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/DTORegistry.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTODecoder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTOEncoder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DTOException.cpp

)
