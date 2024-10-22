/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Server.cpp
*/

#include "Server.hpp"
#include <thread>
#include <iostream>
#include <chrono>

RType::Server::Server(const unsigned short tcpPort, const unsigned short udpPort) :
    _network(new Network::Server(tcpPort, udpPort)), _gameLogic(new GameLogic(0.10)),
    _deltaTimeNetwork(0), _minDeltaTimeNetwork(0.01f), _isRunning(false),
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
    std::thread const network_thread([&]() {
            this->_network->start(this);
    });
    std::cout << "Server started on TCP port " << this->_tcpPort << " and UDP port " << this->_udpPort << '\n';

    this->_isRunning = true;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::system_clock::time_point end;

    float deltaT = 0;


    while (this->_isRunning) {
        end = std::chrono::high_resolution_clock::now();
        deltaT = std::chrono::duration<float, std::chrono::seconds::period>(end - start).count();
        start = end;
        this->_gameLogic->loop(deltaT);
        this->_deltaTimeNetwork += deltaT;
        if (this->_deltaTimeNetwork >= this->_minDeltaTimeNetwork) {
            this->sendUpdateEntities();
            this->_deltaTimeNetwork = this->_deltaTimeNetwork - this->_minDeltaTimeNetwork;
        }
        if (!this->_gameLogic->getEntityManager()->getEntityCreationBuffer().empty()) {
            std::cout << "Creating buffered entities" << '\n';
            this->createBufferedEntities();
        }
        if (!this->_gameLogic->getEntityManager()->getEntityDeletionBuffer().empty()) {
            std::cout << "Deleting buffered entities" << '\n';
            this->deleteBufferedEntities();
        }
        if (this->_network->get_size_recv_queue() > 0) {
            this->handleClientInput();
        }
    }
}

void RType::Server::sendUpdateEntities() const
{
    int nbUpdatedEntities = 0;
    for (auto &[entityId, entity] : this->_gameLogic->getEntityManager()->getEntities())
    {
        IDTO *positionDTO = new EntityPositionDTO(entity->getId(), entity->getEntityType(), static_cast<int>(entity->getPosX()), static_cast<int>(entity->getPosY()));
        std::vector<char> const data = this->_encoder->encode(*positionDTO);
        for (const auto &clientId : this->_network->get_connected_clients())
        {
            this->_network->send_udp_data(data, clientId);
        }
        nbUpdatedEntities++;
    }
}

void RType::Server::createBufferedEntities() const
{
    std::unordered_map<int, IEntity *> const entities = this->_gameLogic->getEntityManager()->getEntityCreationBuffer();


    for (const auto &[entityId, entity] : entities)
    {
        IDTO *creationDTO = new EntityCreationDTO(entity->getId(), entity->getEntityType(), static_cast<int>(entity->getPosX()), static_cast<int>(entity->getPosY()));
        std::vector<char> const data = this->_encoder->encode(*creationDTO);
        for (const auto &clientId : this->_network->get_connected_clients())
        {
            this->_network->send_udp_data(data, clientId);
        }
        this->_gameLogic->getEntityManager()->addEntity(entity);
        this->_gameLogic->getEntityManager()->getEntityCreationBuffer().erase(entityId);
    }
}

void RType::Server::deleteBufferedEntities() const
{
    std::unordered_map<int, IEntity *> const entities = this->_gameLogic->getEntityManager()->getEntityDeletionBuffer();

    for (const auto &[entityId, entity] : entities)
    {
        IDTO *deletionDTO = new EntityDeletionDTO(entity->getId(), entity->getEntityType());
        std::vector<char> const data = this->_encoder->encode(*deletionDTO);
        for (const auto &clientId : this->_network->get_connected_clients())
        {
            this->_network->send_udp_data(data, clientId);
        }
        this->_gameLogic->getEntityManager()->deleteEntity(entityId);
        this->_gameLogic->getEntityManager()->getEntityDeletionBuffer().erase(entityId);
    }
}

int RType::Server::createNewPlayer() const
{
    std::cout << "Creating new player" << '\n';
    return this->_gameLogic->createPlayer();
}

void RType::Server::handleClientInput() const
{
    std::unordered_map<int, std::vector<char>> data = this->_network->get_next_recv_queue();

    for (auto &[clientId, clientData] : data)
    {
        IDTO *dto = this->_decoder->decode(clientData);
        const auto *playerStartDTO = dynamic_cast<PlayerActionStartDTO *>(dto);
        if (playerStartDTO != nullptr)
        {
            std::cout << "Player " << clientId << " started action: " << playerStartDTO->getAction() << '\n';
            this->_gameLogic->handlePlayerStart(playerStartDTO);
            continue;
        }
        const auto *playerStopDTO = dynamic_cast<PlayerActionStopDTO *>(dto);
        if (playerStopDTO != nullptr)
        {
            std::cout << "Player " << clientId << " stopped action: " << playerStopDTO->getAction() << '\n';
            this->_gameLogic->handlePlayerStop(playerStopDTO);
            continue;
        }
        std::cout << "Unknown DTO" << '\n';
    }
}
