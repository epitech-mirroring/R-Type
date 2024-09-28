cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(R-Type-Reborn
        LANGUAGES CXX)

include_directories(includes)
link_directories(libs)
link_libraries(StellarForge)

add_executable(R-Type-Reborn ${R-Type-Reborn_SOURCES}
        src/network/server/server.cpp)
find_package(asio CONFIG REQUIRED)
target_link_libraries(R-Type-Reborn PRIVATE asio::asio)

add_subdirectory(src)
