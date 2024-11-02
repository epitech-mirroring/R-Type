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
#include "StellarForge/engine/Engine.hpp"
#include "StellarForge/Common/factories/ComponentFactory.hpp"
#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <host> <UDP port> <TCP port>" << std::endl;
        return 1;
    }

    try {
        Engine const engine([]() {
            REGISTER_COMPONENT(Background);
            REGISTER_COMPONENT(NetworkManager);
        }, "R-Type-Reborn");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
