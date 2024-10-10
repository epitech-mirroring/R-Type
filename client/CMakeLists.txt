add_executable(client)

target_sources(client
        PUBLIC
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(client PRIVATE ${MY_LIBRARY})
