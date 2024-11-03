add_executable(r-type_client)

target_link_libraries(r-type_client PUBLIC stellar-forge::stellar-forge sfml::sfml glm::glm PRIVATE rtype::network)

target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/Background.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/NetworkManager.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/Menu.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/GameOverMenu.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/Background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/NetworkManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/Menu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../assets/objects/scripts/GameOverMenu.cpp
)
