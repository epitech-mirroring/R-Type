add_subdirectory(groups)

target_sources(r-type_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/AField.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FileField.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Vector3Field.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StringField.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FloatField.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/AField.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FileField.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Vector3Field.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StringField.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FloatField.cpp
)
