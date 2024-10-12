/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.cpp
*/

#include "StellarForge/common/components/CPPMonoBehaviour.hpp"
#include "../../ApplyDTO.hpp"
#include "client/Client.hpp"
#include "NetworkException.hpp"
#include <iostream>

class NetworkManager : public CPPMonoBehaviour {
private:
    std::shared_ptr<Network::Client> _client = nullptr;
    DTORegistry *_dtoRegistry = nullptr;
    int _playerId = -1;
public:
    NetworkManager() = default;
    ~NetworkManager() = default;

    void start() {
        // Create client
        _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445);
        _dtoRegistry = new DTORegistry();
        // Connect to server
        try {
            _client->connect();
            std::cout << "Connected to server" << std::endl;
        } catch (const NetworkException& e) {
            std::cerr << "Failed to connect to server: " << e.what() << std::endl;
            return;
        }

        // Get player id
        _playerId = _client->getId();
        std::cout << "Player ID: " << _playerId << std::endl;

        // EventSystem::registerListener("z_pressed", &getEventData);
        // EventSystem::registerListener("z_released", &getEventData);
        // EventSystem::registerListener("s_pressed", &getEventData);
        // EventSystem::registerListener("s_released", &getEventData);
        // EventSystem::registerListener("q_pressed", &getEventData);
        // EventSystem::registerListener("q_released", &getEventData);
        // EventSystem::registerListener("d_pressed", &getEventData);
        // EventSystem::registerListener("d_released", &getEventData);
        // EventSystem::registerListener("space_pressed", &getEventData);
        // EventSystem::registerListener("space_released", &getEventData);
    }
    /*void start() {
        // Create client
        // Connect to server
        // (Get player id)

        // EventSystem::registerListener("z_pressed", &getEventData);
        // EventSystem::registerListener("z_released", &getEventData);
        // EventSystem::registerListener("s_pressed", &getEventData);
        // EventSystem::registerListener("s_released", &getEventData);
        // EventSystem::registerListener("q_pressed", &getEventData);
        // EventSystem::registerListener("q_released", &getEventData);
        // EventSystem::registerListener("d_pressed", &getEventData);
        // EventSystem::registerListener("d_released", &getEventData);
        // EventSystem::registerListener("space_pressed", &getEventData);
        // EventSystem::registerListener("space_released", &getEventData);
    }
    */

    void update() {
        // Receive data from the server
        _client->receive_udp_data();

        // Check if there is data in the receive queue
        while (_client->get_size_recv_queue() > 0) {
            // Get the next data from the receive queue
            std::vector<char> data = _client->get_next_recv_queue();

            // Apply the DTOs
            applyDTOs(data, _dtoRegistry);
        }
    }
    /*
    void update() {
        // Receive data

        // si data Update game

            if (new entity)
                ObjectManager::addObject(entity id, entity)

            if (entity destroyed)
                ObjectManager::removeObject(entity id)

            if (entity updated)
                if (position updated)
                    object = ObjectManager::getObject(entity id)
                    object->getComponent("Transform")->setPosition(new position)
                ...
    }
    */

    void getEventData(EventData data) {
        std::string name = data.getName();
        auto player = ObjectManager::getObject(playerId);
        PlayerAction action;

        if (name.ends_with("_pressed")) {
            if (name == "z_pressed") action = PlayerAction::MOVE_UP;
            else if (name == "s_pressed") action = PlayerAction::MOVE_DOWN;
            else if (name == "q_pressed") action = PlayerAction::MOVE_LEFT;
            else if (name == "d_pressed") action = PlayerAction::MOVE_RIGHT;
            else if (name == "space_pressed") action = PlayerAction::SHOOT;

            PlayerActionStartDTO dto = PlayerActionStartDTO();
            dto.setPlayerId(_playerId);
            dto.setAction(action);
            _client->send_udp_data(dto.serialize());
        } else if (name.ends_with("_released")) {
            if (name == "z_released") action = PlayerAction::MOVE_UP;
            else if (name == "s_released") action = PlayerAction::MOVE_DOWN;
            else if (name == "q_released") action = PlayerAction::MOVE_LEFT;
            else if (name == "d_released") action = PlayerAction::MOVE_RIGHT;
            else if (name == "space_released") action = PlayerAction::SHOOT;

            PlayerActionStopDTO dto = PlayerActionStopDTO();
            dto.setPlayerId(_playerId);
            dto.setAction(action);
            _client->send_udp_data(dto.serialize());
        }

    }
    /*
    void getEventData(EventData data) {
        //name = data->getName()
        //player = ObjectManager::getObject(playerId)
        //if name ends with _pressed
            //action = z -> PlayerAction::MOVE_UP, s -> PlayerAction::MOVE_DOWN, q -> PlayerAction::MOVE_LEFT, d -> PlayerAction::MOVE_RIGHT, space -> PlayerAction::SHOOT
            //create PlayerActionStartDTO(playerId, action)
            //sendData
        //if name ends with _released
            //action = z -> PlayerAction::MOVE_UP, s -> PlayerAction::MOVE_DOWN, q -> PlayerAction::MOVE_LEFT, d -> PlayerAction::MOVE_RIGHT, space -> PlayerAction::STOP_SHOOT
            //create PlayerActionStopDTO(playerId, action)
            //sendData
    }

    void sendData() {
        //send data to server
    }
    */
};