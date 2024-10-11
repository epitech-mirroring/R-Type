add_executable(r-type_client)

target_link_libraries(r-type_client PRIVATE StellarForge)

target_sources(r-type_client
        PUBLIC
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
