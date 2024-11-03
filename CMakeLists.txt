cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

# if macos set drag n drop generator for cpack
if (APPLE)
    set(CPACK_GENERATOR "DragNDrop")
else ()
    if (WIN32)
        set(CPACK_GENERATOR "NSIS")
    else ()
        set(CPACK_GENERATOR "ZIP")
    endif ()
endif ()
include(CPack)

project(R-Type-Reborn
        LANGUAGES CXX)


include_directories(includes)
include_directories(includes/StellarForge)
include_directories(network)


link_directories(libs)

find_package(asio REQUIRED)
find_package(glm REQUIRED)
find_package(SFML REQUIRED COMPONENTS graphics window system)
find_package(stellar-forge REQUIRED)

add_subdirectory(network)
add_subdirectory(client)
add_subdirectory(server)

install(TARGETS r-type_client DESTINATION .)
install(TARGETS r-type_server DESTINATION .)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PROJECT_VENDOR "Epitech-Mirroring")
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_INSTALL_CMAKE_PROJECTS "${CMAKE_CURRENT_BINARY_DIR};R-Type-Reborn;ALL;/")

install(DIRECTORY assets DESTINATION .)
