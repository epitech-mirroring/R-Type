add_executable(r-type_client)

# Add the link to the libraries of the Game Engine here
# target_link_libraries(r-type_server PRIVATE StellarForge)

target_sources(r-type_client
        PUBLIC
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
