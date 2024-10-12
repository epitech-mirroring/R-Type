/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "client/Client.hpp"
#include "dto/DTODecoder.hpp"
#include "dto/DTORegistry.hpp"
#include "dto/entity/EntityPositionDTO.hpp"
#include "dto/entity/EntityCreationDTO.hpp"
#include "dto/entity/EntityDeletionDTO.hpp"
#include <iostream>
#include <thread>

std::ostream &operator<<(std::ostream &os, const EntityType &type) {
    switch (type) {
    case NO_TYPE:
        os << "NO_TYPE";
        break;
    case PLAYER:
        os << "PLAYER";
        break;
    case ENEMY:
        os << "ENEMY";
        break;
    case BULLET:
        os << "BULLET";
        break;
    }
    return os;
}

void printDTO(IDTO* dto)
{
    auto* entityPositionDTO = dynamic_cast<EntityPositionDTO*>(dto);
    if (entityPositionDTO != nullptr)
    {
        std::cout << "EntityPositionDTO: " << entityPositionDTO->getEntityId() << " " << entityPositionDTO->getEntityType() << " " << entityPositionDTO->getPosX() << " " << entityPositionDTO->getPosY() << std::endl;
        return;
    }
    auto* entityCreationDTO = dynamic_cast<EntityCreationDTO*>(dto);
    if (entityCreationDTO != nullptr)
    {
        std::cout << "EntityCreationDTO: " << entityCreationDTO->getEntityId() << " " << entityCreationDTO->getEntityType() << " " << entityCreationDTO->getPosX() << " " << entityCreationDTO->getPosY() << std::endl;
        return;
    }
    auto* entityDeletionDTO = dynamic_cast<EntityDeletionDTO*>(dto);
    if (entityDeletionDTO != nullptr)
    {
        std::cout << "EntityDeletionDTO: " << entityDeletionDTO->getEntityId() << " " << entityDeletionDTO->getEntityType() << std::endl;
        return;
    }
    std::cout << "Unknown DTO" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <host> <UDP port> <TCP port>" << std::endl;
        return 1;
    }

    const std::string host = argv[1];
    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[2]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[3]));

    try {
        Network::Client client(host, UDP_port, TCP_port);
        std::cout << "Client trying to connect to server..." << std::endl;
        client.connect();
        std::cout << "Client connected to server" << std::endl;

        DTORegistry *registry = new DTORegistry();
        DTODecoder *decoder = new DTODecoder(registry);

        while(true){
            if (client.get_size_recv_queue() > 0) {
                std::vector<char> data = client.get_next_recv_queue();
                std::cout << "data received: " << "\n";
                IDTO* dto = decoder->decode(data);
                printDTO(dto);
                std::cout << std::endl;
            }
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
