/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Server.cpp
*/

#include "Server.hpp"
#include <thread>
#include <iostream>
#include <ctime>

RType::Server::Server(const unsigned short tcpPort, const unsigned short udpPort) :
    _network(new Network::Server(tcpPort, udpPort)), _gameLogic(new GameLogic(0.10)),
    _deltaTimeNetwork(0), _minDeltaTimeNetwork(1.0f), _isRunning(false),
    _tcpPort(tcpPort), _udpPort(udpPort)
{
    auto *registry = new DTORegistry();
    this->_encoder = new DTOEncoder(registry);
    this->_decoder = new DTODecoder(registry);
}

RType::Server::~Server()
{
    delete this->_network;
    delete this->_gameLogic;
    delete this->_encoder;
    delete this->_decoder;
}

void RType::Server::runServer()
{
    std::thread network_thread([&]() {
            this->_network->start(this);
    });
    std::cout << "Server started on TCP port " << this->_tcpPort << " and UDP port " << this->_udpPort << std::endl;

    this->_isRunning = true;
    clock_t currentTime = clock();
    clock_t newTime = 0;
    float deltaT = 0;


    while (this->_isRunning) {
        newTime = clock();
        deltaT = static_cast<float>(newTime - currentTime) / CLOCKS_PER_SEC;
        currentTime = newTime;
        this->_gameLogic->loop(deltaT);
        this->_deltaTimeNetwork += deltaT;
        if (this->_deltaTimeNetwork >= this->_minDeltaTimeNetwork) {
            this->sendUpdateEntities();
            this->_deltaTimeNetwork = this->_deltaTimeNetwork - this->_minDeltaTimeNetwork;
        }
        this->createBufferedEntities();
        this->deleteBufferedEntities();
        this->handleClientInput();
    }
}

void RType::Server::sendUpdateEntities()
{
    int nbUpdatedEntities = 0;
    for (auto &[entityId, entity] : this->_gameLogic->getEntityManager()->getEntities())
    {
        std::cout << "Sending entity " << entity->getId() << " position (" << entity->getPosX() << ", " << entity->getPosY() << ")" << std::endl;
        IDTO *positionDTO = new EntityPositionDTO(entity->getId(), entity->getEntityType(), entity->getPosX(), entity->getPosY());
        std::vector<char> data = this->_encoder->encode(*positionDTO);
        for (const auto &clientId : this->_network->get_connected_clients())
        {
            this->_network->add_to_udp_send_queue(data, clientId);
        }
        nbUpdatedEntities++;
    }
    if (nbUpdatedEntities > 0) {
        std::cout << "Sent " << nbUpdatedEntities << " entities" << std::endl;
    }
}

void RType::Server::createBufferedEntities()
{
    std::unordered_map<int, IEntity *> entities = this->_gameLogic->getEntityManager()->getEntityCreationBuffer();

    for (auto &[entityId, entity] : entities)
    {
        IDTO *creationDTO = new EntityCreationDTO(entity->getId(), entity->getEntityType(), entity->getPosX(), entity->getPosY());
        std::vector<char> data = this->_encoder->encode(*creationDTO);
        for (const auto &clientId : this->_network->get_connected_clients())
        {
            this->_network->add_to_udp_send_queue(data, clientId);
        }
        this->_gameLogic->getEntityManager()->addEntity(entity);
        this->_gameLogic->getEntityManager()->getEntityCreationBuffer().erase(entityId);
    }
}

void RType::Server::deleteBufferedEntities()
{
    std::unordered_map<int, IEntity *> entities = this->_gameLogic->getEntityManager()->getEntityDeletionBuffer();

    for (auto &[entityId, entity] : entities)
    {
        IDTO *deletionDTO = new EntityDeletionDTO(entity->getId(), entity->getEntityType());
        std::vector<char> data = this->_encoder->encode(*deletionDTO);
        for (const auto &clientId : this->_network->get_connected_clients())
        {
            this->_network->add_to_udp_send_queue(data, clientId);
        }
        this->_gameLogic->getEntityManager()->deleteEntity(entityId);
        this->_gameLogic->getEntityManager()->getEntityDeletionBuffer().erase(entityId);
    }
}

int RType::Server::createNewPlayer() const
{
    std::cout << "Creating new player" << std::endl;
    return this->_gameLogic->createPlayer();
}


std::ostream &operator<<(std::ostream &os, const PlayerAction &action) {
    switch (action) {
        case NO_ACTION:
            os << "NO_ACTION";
            break;
        case MOVE_UP:
            os << "MOVE_UP";
            break;
        case MOVE_DOWN:
            os << "MOVE_DOWN";
            break;
        case MOVE_LEFT:
            os << "MOVE_LEFT";
            break;
        case MOVE_RIGHT:
            os << "MOVE_RIGHT";
            break;
        case SHOOT:
            os << "SHOOT";
            break;
    }
    return os;
}

void RType::Server::handleClientInput()
{
    std::unordered_map<int, std::vector<char>> data = this->_network->get_next_recv_queue();

    for (auto &[clientId, clientData] : data)
    {
        IDTO *dto = this->_decoder->decode(clientData);
        auto *playerStartDTO = dynamic_cast<PlayerActionStartDTO *>(dto);
        if (playerStartDTO != nullptr)
        {
            std::cout << "Player " << clientId << " started action: " << playerStartDTO->getAction() << std::endl;
            this->_gameLogic->handlePlayerStart(playerStartDTO);
            continue;
        }
        auto *playerStopDTO = dynamic_cast<PlayerActionStopDTO *>(dto);
        if (playerStopDTO != nullptr)
        {
            std::cout << "Player " << clientId << " stopped action: " << playerStopDTO->getAction() << std::endl;
            this->_gameLogic->handlePlayerStop(playerStopDTO);
            continue;
        }
        std::cout << "Unknown DTO" << std::endl;
    }
}
