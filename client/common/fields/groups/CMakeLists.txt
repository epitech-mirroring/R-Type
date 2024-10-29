target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/AFieldGroup.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/InvisibleFieldGroup.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/AFieldGroup.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/InvisibleFieldGroup.cpp
)
