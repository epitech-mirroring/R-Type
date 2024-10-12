/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.cpp
*/

#include "StellarForge/common/components/CPPMonoBehaviour.hpp"

class NetworkManager : public CPPMonoBehaviour {
public:
    NetworkManager() = default;
    ~NetworkManager() = default;
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