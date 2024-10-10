cmake_minimum_required(VERSION 3.29)

project(R-Type-Reborn
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(includes)

set(LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs")

find_library(MY_LIBRARY NAMES StellarForge PATHS ${LIBRARY_PATH})

# Vérifier si la bibliothèque a été trouvée
if(NOT MY_LIBRARY)
    message(FATAL_ERROR "Library StellarForge not found in ${LIBRARY_PATH}")
endif()

add_subdirectory(client)
add_subdirectory(server)
