/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "client/Client.hpp"
#include "../assets/objects/scripts/NetworkManager.hpp"
#include "../assets/objects/scripts/Background.hpp"
#include "../assets/objects/scripts/Menu.hpp"
#include "StellarForge/Engine/Engine.hpp"
#include "StellarForge/Common/factories/ComponentFactory.hpp"
#include "StellarForge/Common/managers/SceneManager.hpp"
#include "StellarForge/Common/UUID.hpp"
#include <iostream>
#include <thread>

int main(void)
{
    try {
        Engine const engine([]() {
            REGISTER_COMPONENT(Background);
            REGISTER_COMPONENT(NetworkManager);
            REGISTER_COMPONENT(Menu);
        }, "R-Type-Reborn", "./assets/", [](const std::string &gameName) {
            UUID menuSceneUuid;
            menuSceneUuid.setUuidFromString("89de1e2b-3599-4416-b0ee-c03d2f9e4e82");
            SceneManager::getInstance().switchToScene(menuSceneUuid);
            Engine::_startGraphics(gameName);
        });
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
