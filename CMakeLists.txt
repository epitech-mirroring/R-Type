cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "/home/simon/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(R-Type-Reborn
        LANGUAGES CXX)


include_directories(includes)
link_directories(libs)
link_libraries(StellarForge)

find_package(asio CONFIG REQUIRED)

add_executable(R-Type-Reborn-client ${R-Type-Reborn_SOURCES}
        tests/client/main.cpp
        src/network/client/client.cpp)
target_link_libraries(R-Type-Reborn-client PRIVATE asio::asio)

add_executable(R-Type-Reborn-server ${R-Type-Reborn_SOURCES}
        tests/server/main.cpp
        src/network/server/server.cpp)
target_link_libraries(R-Type-Reborn-server PRIVATE asio::asio)


add_subdirectory(src/network)
#add_subdirectory(tests)
