cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)

project(R-Type-Reborn
        LANGUAGES CXX)


include_directories(includes)
link_directories(libs)
link_libraries(StellarForge)

find_package(asio REQUIRED)

add_subdirectory(src/network)

add_executable(R-Type-Reborn-server tests/server/main.cpp)
target_link_libraries(R-Type-Reborn-server PRIVATE rtype::network)

add_executable(R-Type-Reborn-client tests/client/main.cpp)
target_link_libraries(R-Type-Reborn-client PRIVATE rtype::network)


include_directories(src/network)
#add_subdirectory(tests)
