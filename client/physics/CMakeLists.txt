add_subdirectory(components)

target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Physics.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Collider.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Box.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sphere.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Physics.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Box.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sphere.cpp
)
