cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 17)

project(R-Type-Reborn
        LANGUAGES CXX)


include_directories(includes)
link_directories(libs)
link_libraries(StellarForge)

find_package(asio REQUIRED)

add_subdirectory(src/network)

add_executable(r-type_server tests/server/main.cpp)
target_link_libraries(r-type_server PRIVATE rtype::network)

add_executable(r-type_client tests/client/main.cpp)
target_link_libraries(r-type_client PRIVATE rtype::network)


include_directories(src/network)
#add_subdirectory(tests)
