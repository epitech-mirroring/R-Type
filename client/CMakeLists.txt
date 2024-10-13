add_executable(r-type_client)

target_link_libraries(r-type_client PUBLIC StellarForge StellarForgeGraphics StellarForgePhysics StellarForgeCommon sfml::sfml stduuid::stduuid PRIVATE rtype::network)
add_subdirectory(dto)


target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/objects/scripts/Background.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/objects/scripts/NetworkManager.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/objects/scripts/Background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/objects/scripts/NetworkManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/BinaryVector.cpp
)
