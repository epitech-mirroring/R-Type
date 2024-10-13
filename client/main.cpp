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
#include "StellarForge/common/factories/ComponentFactory.hpp"
#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <host> <UDP port> <TCP port>" << std::endl;
        return 1;
    }

    const std::string host = argv[1];
    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[2]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[3]));

    Engine engine([]() {
        REGISTER_COMPONENT(Background);
        REGISTER_COMPONENT(NetworkManager);
    }, "R-Type-Reborn");
    return 0;
}
