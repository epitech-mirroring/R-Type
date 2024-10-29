add_executable(r-type_client)

target_link_libraries(r-type_client PUBLIC sfml::sfml glm::glm PRIVATE rtype::network)
add_subdirectory(dto)
add_subdirectory(common)
add_subdirectory(engine)
add_subdirectory(graphics)
add_subdirectory(physics)

target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/Background.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/NetworkManager.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/Background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/NetworkManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.cpp
)
