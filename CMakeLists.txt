cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

project(R-Type-Reborn VERSION 1.0 LANGUAGES CXX)

# Set up CPack generator based on the platform
if (APPLE)
    set(CPACK_GENERATOR "DragNDrop")
elseif (WIN32)
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_NSIS_DISPLAY_NAME "R-Type-Reborn")
    set(CPACK_NSIS_PACKAGE_NAME "R-Type-Reborn Installer")
    set(CPACK_NSIS_CONTACT "mirroring@epitech.com")
    set(CPACK_NSIS_HELP_LINK "https://wiki.simon-gl.fr/")
    set(CPACK_NSIS_URL_INFO_ABOUT "https://wiki.simon-gl.fr/")
    set(CPACK_NSIS_INSTALLED_ICON_NAME bin\\\\r-type_client.exe)
    set(CPACK_NSIS_CREATE_ICONS_EXTRA
            "CreateShortCut '$DESKTOP\\\\R-Type-client.lnk' '$INSTDIR\\\\bin\\\\r-type_client.exe' '1 1 1' '$INSTDIR'
            CreateShortCut '$DESKTOP\\\\R-Type-server.lnk' '$INSTDIR\\\\bin\\\\r-type_server.exe' '4444 4445' '$INSTDIR'
            CreateShortCut '$DESKTOP\\\\R-Type-uninstaller.lnk' '$INSTDIR\\\\Uninstall.exe' '$INSTDIR'")
    set(CPACK_NSIS_DELETE_ICONS_EXTRA
            "Delete '$DESKTOP\\\\R-Type-client.lnk'
            Delete '$DESKTOP\\\\R-Type-server.lnk'
            Delete '$DESKTOP\\\\R-Type-uninstaller.lnk'")
    set(CPACK_NSIS_MODIFY_PATH ON)
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
else()
    set(CPACK_GENERATOR "RPM")
    set(CPACK_RPM_PACKAGE_LICENSE "MIT")
    set(CPACK_RPM_PACKAGE_RELOCATABLE FALSE)
    set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
endif()
include(CPack)

# Include directories and link libraries
include_directories(includes)
include_directories(includes/StellarForge)
include_directories(network)
link_directories(libs)

find_package(asio REQUIRED)
find_package(glm REQUIRED)
find_package(SFML REQUIRED COMPONENTS graphics window system)
find_package(stellar-forge REQUIRED)

# Add subdirectories for client, server, and network modules
add_subdirectory(network)
add_subdirectory(client)
add_subdirectory(server)

if (WIN32)
    install(TARGETS r-type_client r-type_server DESTINATION bin)
    install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets DESTINATION .)
else ()
    install(TARGETS r-type_client DESTINATION .)
    install(TARGETS r-type_server DESTINATION .)
    install(DIRECTORY assets DESTINATION .)
endif ()

# CPack configuration
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PROJECT_VENDOR "Epitech-Mirroring")
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_INSTALL_CMAKE_PROJECTS "${CMAKE_BINARY_DIR};${PROJECT_NAME};ALL;/")
