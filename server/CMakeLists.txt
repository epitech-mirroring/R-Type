add_executable(r-type_server)

# Add the link to the libraries of the Game Engine here
# target_link_libraries(r-type_server PRIVATE StellarForge)

target_link_libraries(r-type_server PUBLIC asio::asio)
target_link_libraries(r-type_server PRIVATE rtype::network)

add_subdirectory(entities)
add_subdirectory(dto)

target_sources(r-type_server
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Server.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GameLogic.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Random.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Server.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Random.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GameLogic.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.cpp
)
