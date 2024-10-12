add_executable(r-type_client)

# Add the link to the libraries of the Game Engine here
target_link_libraries(r-type_client PRIVATE rtype::network)

add_subdirectory(dto)

target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.cpp
)

