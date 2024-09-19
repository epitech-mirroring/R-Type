cmake_minimum_required(VERSION 3.5)

project(R-Type-Reborn
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(includes)
link_directories(libs)
link_libraries(StellarForge)

add_executable(R-Type-Reborn ${R-Type-Reborn_SOURCES})

add_subdirectory(src)
