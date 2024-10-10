add_executable(r-type_server)

target_sources(r-type_server
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Server.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GameLogic.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/IEntity.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/AEntity.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/AShip.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/ABullet.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/Player.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/BasicEnemy.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/ClassicBullet.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/EntityManager.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Server.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/GameLogic.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/AEntity.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/AShip.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/ABullet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/Player.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/BasicEnemy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/ClassicBullet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/entities/EntityManager.cpp
)

target_link_libraries(r-type_server PRIVATE ${MY_LIBRARY})
