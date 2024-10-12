/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.cpp
*/

#include "StellarForge/common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/common/components/Transform.hpp"
#include "StellarForge/common/event/EventSystem.hpp"
#include "StellarForge/common/managers/ObjectManager.hpp"

#include "../dto/DTORegistry.hpp"
#include "../dto/DTODecoder.hpp"
#include "../dto/entity/EntityCreationDTO.hpp"
#include "../dto/entity/EntityDeletionDTO.hpp"
#include "../dto/entity/EntityPositionDTO.hpp"
#include "../dto/entity/EntityTypeEnum.hpp"
#include "../dto/player/PlayerActionEnum.hpp"
#include "../dto/player/PlayerActionStartDTO.hpp"
#include "../dto/player/PlayerActionStopDTO.hpp"

#include "../../network/client/Client.hpp"
#include "../../network/NetworkException.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>
#include <vector>
#include <iostream>

class NetworkManager : public CPPMonoBehaviour {
public:
    NetworkManager() = default;
    ~NetworkManager() = default;

    static const std::unordered_map<std::string, EntityType> _entityTypesUuids;

    void start() {
        _client = std::make_shared<Network::Client>("127.0.0.1", 4444, 4445); // TODO get from config
        _dtoRegistry = new DTORegistry();
        try {
            _client->connect();
            std::cout << "Connected to server" << std::endl;
        } catch (const NetworkException& e) {
            std::cerr << "Failed to connect to server: " << e.what() << std::endl;
            return;
        }

        _playerId = _client->getId();
        std::cout << "Player ID: " << _playerId << std::endl;

        EventSystem::getInstance().registerListener("z_pressed", &getEventData);
        EventSystem::getInstance().registerListener("z_released", &getEventData);
        EventSystem::getInstance().registerListener("s_pressed", &getEventData);
        EventSystem::getInstance().registerListener("s_released", &getEventData);
        EventSystem::getInstance().registerListener("q_pressed", &getEventData);
        EventSystem::getInstance().registerListener("q_released", &getEventData);
        EventSystem::getInstance().registerListener("d_pressed", &getEventData);
        EventSystem::getInstance().registerListener("d_released", &getEventData);
        EventSystem::getInstance().registerListener("space_pressed", &getEventData);
        EventSystem::getInstance().registerListener("space_released", &getEventData);
    }

    void update() {
        _client->receive_udp_data();

        while (_client->get_size_recv_queue() > 0) {
            std::vector<char> data = _client->get_next_recv_queue();
            applyDTOs(data, _dtoRegistry);
        }
    }

    void getEventData(EventData data) {
        std::string name = data.name;
        auto *player = ObjectManager::getInstance().getObjectById(_playerUuid);
        PlayerAction action;

        std::string key = name.substr(0, name.find("_"));
        std::string actionName = name.substr(name.find("_") + 1, name.size());

        if (key == "z") action = PlayerAction::MOVE_UP;
        else if (key == "s") action = PlayerAction::MOVE_DOWN;
        else if (key == "q") action = PlayerAction::MOVE_LEFT;
        else if (key == "d") action = PlayerAction::MOVE_RIGHT;
        else if (key == "space") action = PlayerAction::SHOOT;

        if (actionName == "pressed") {
            PlayerActionStartDTO dto;
            dto.setPlayerId(_playerId);
            dto.setAction(action);
            _client->send_udp_data(dto.serialize());
        } else if (actionName == "released") {
            PlayerActionStopDTO dto;
            dto.setPlayerId(_playerId);
            dto.setAction(action);
            _client->send_udp_data(dto.serialize());
        }
    }

    void applyDTO(EntityCreationDTO* dto) {
        UUID baseUuid;
        std::string baseUuidStr;
        for (auto& entityTypeUuid : _entityTypesUuids) {
            if (entityTypeUuid.first == dto->getEntityType()) {
                baseUuidStr = entityTypeUuid.second;
                break;
            }
        }
        if (dto->getEntityId() == _playerId) {
            baseUuidStr = "4"; // TODO: get from config
        }

        if (baseUuidStr.empty()) {
            std::cerr << "Unknown entity type" << std::endl;
            return;
        }

        baseUuid.setUuidFromString(baseUuidStr);
        UUID uuid = ObjectManager::getInstance().duplicateObject(baseUuid);
        IObject* object = ObjectManager::getInstance().getObjectById(uuid);
        object->setActive(true);
        _idsToUuids.push_back({dto->getEntityId(), uuid});
        if (dto->getEntityId() == _playerId) {
            _playerUuid = uuid;
        }
    }

    void applyDTO(EntityDeletionDTO* dto) {
        for (auto it = _idsToUuids.begin(); it != _idsToUuids.end(); ++it) {
            if (it->first == dto->getEntityId()) {
                ObjectManager::getInstance().removeObject(it->second);
                _idsToUuids.erase(it);
                break;
            }
        }
    }

    void applyDTO(EntityPositionDTO* dto) {
        for (auto& idUuidPair : _idsToUuids) {
            if (idUuidPair.first == dto->getEntityId()) {
                IObject* object = ObjectManager::getInstance().getObjectById(idUuidPair.second);
                Transform* transform = nullptr;
                for (auto component : object->getComponents()) {
                    if (component->getMeta().getName() == "Transform") {
                        transform = dynamic_cast<Transform*>(component);
                        transform->setPosition(Vector3(dto->getPosX(), dto->getPosY(), 0));
                        break;
                    }
                }
            }
        }
    }

    void applyDTOs(std::vector<char> data, DTORegistry* dtoRegistry) {
        DTODecoder decoder(dtoRegistry);
        IDTO* dto = decoder.decode(data);

        if (dynamic_cast<EntityCreationDTO*>(dto) != nullptr) {
            applyDTO(dynamic_cast<EntityCreationDTO*>(dto));
        } else if (dynamic_cast<EntityDeletionDTO*>(dto) != nullptr) {
            applyDTO(dynamic_cast<EntityDeletionDTO*>(dto));
        } else if (dynamic_cast<EntityPositionDTO*>(dto) != nullptr) {
            applyDTO(dynamic_cast<EntityPositionDTO*>(dto));
        }
    }

private:
    std::shared_ptr<Network::Client> _client = nullptr;
    DTORegistry* _dtoRegistry = nullptr;
    int _playerId = -1;
    UUID _playerUuid;
    std::vector<std::pair<int, UUID>> _idsToUuids = {};
    std::vector<std::pair<EntityType, std::string>> _entityTypesUuids = {
        {EntityType::PLAYER, "4"},
        {EntityType::ENEMY, "1"},
        {EntityType::BULLET, "2"}
    };
};
