/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.cpp
*/

#include "NetworkManager.hpp"

NetworkManager::NetworkManager(IObject *owner, const json::IJsonObject *data)
    : CPPMonoBehaviour(owner) {}

void NetworkManager::start() {
    std::cout << "!!! Starting network manager !!!" << std::endl;
    _client = std::make_shared<Network::Client>("127.0.0.1", 4445, 4444); // TODO get from config
    _dtoRegistry = new DTORegistry();
    _dtoEncoder = new DTOEncoder(_dtoRegistry);
    _dtoDecoder = new DTODecoder(_dtoRegistry);
    try {
        _client->connect();
        std::cout << "Connected to server" << std::endl;
    } catch (const NetworkException& e) {
        std::cerr << "Failed to connect to server: " << e.what() << std::endl;
        return;
    }

    _playerId = _client->getId();
    std::cout << "Player ID: " << _playerId << std::endl;

    EventSystem::getInstance().registerListener("z_pressed", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("z_released", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("s_pressed", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("s_released", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("q_pressed", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("q_released", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("d_pressed", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("d_released", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("space_pressed", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    EventSystem::getInstance().registerListener("space_released", std::bind(&NetworkManager::getEventData, this, std::placeholders::_1));
    std::cout << "!!! Network manager started !!!" << std::endl;
}

void NetworkManager::update() {
    while (_client->get_size_recv_queue() > 0) {
        std::vector<char> data = _client->get_next_recv_queue();
        applyDTOs(data);
    }
}

void NetworkManager::getEventData(EventData data) {
    std::string name = data.name;
    PlayerAction action;
    std::cout << "Event name: " << name << std::endl;

    std::string key = name.substr(0, name.find("_"));
    std::string actionName = name.substr(name.find("_") + 1, name.size());

    if (key == "z") action = PlayerAction::MOVE_UP;
    else if (key == "s") action = PlayerAction::MOVE_DOWN;
    else if (key == "q") action = PlayerAction::MOVE_LEFT;
    else if (key == "d") action = PlayerAction::MOVE_RIGHT;
    else if (key == "space") action = PlayerAction::SHOOT;

    if (actionName == "pressed") {
        std::cout << "Sending action: " << action << " and player id: " << _playerId << std::endl;
        PlayerActionStartDTO dto;
        dto.setPlayerId(_playerId);
        dto.setAction(action);
        std::cout << "Sending action: " << dto.getAction() << " and player id: " << dto.getPlayerId() << std::endl;
        _client->send_udp_data(_dtoEncoder->encode(dto));
    } else if (actionName == "released") {
        std::cout << "Sending action: " << action << " and player id: " << _playerId << std::endl;
        PlayerActionStopDTO dto;
        dto.setPlayerId(_playerId);
        dto.setAction(action);
        _client->send_udp_data(_dtoEncoder->encode(dto));
    }
}

void NetworkManager::applyDTO(EntityCreationDTO* dto) {
    std::cout << "Applying entity creation" << std::endl;
    UUID baseUuid;
    std::string baseUuidStr;
    for (auto& entityTypeUuid : _entityTypesUuids) {
        if (entityTypeUuid.first == dto->getEntityType()) {
            baseUuidStr = entityTypeUuid.second;
            break;
        }
    }
    if (dto->getEntityId() == _playerId) {
        std::cout << "Player entity creation" << std::endl;
        baseUuidStr = "d9e329e7-b3bf-412e-86a5-f8e18f710756"; // TODO: get from config
    }

    if (baseUuidStr.empty()) {
        std::cerr << "Unknown entity type" << std::endl;
        return;
    }

    baseUuid.setUuidFromString(baseUuidStr);
    UUID uuid = ObjectManager::getInstance().duplicateObject(baseUuid);
    std::cout << "Object UUID: " << uuid.getUuidString() << std::endl;
    IObject* object = ObjectManager::getInstance().getObjectById(uuid);
    std::cout << "Object name: " << object->getMeta().getName() << std::endl;
    object->setActive(true);
    ObjectManager::getInstance().updateObject(uuid, object);
    std::cout << "is active: " << object->isActive() << std::endl;
    for (auto component : object->getComponents()) {
        if (component->getMeta().getName() == "Transform") {
            Transform* transform = dynamic_cast<Transform*>(component);
            transform->setPosition(Vector3(dto->getPosX(), dto->getPosY(), 0));
            break;
        }
    }
    _idsToUuids.push_back({dto->getEntityId(), uuid});
    if (dto->getEntityId() == _playerId) {
        _playerUuid = uuid;
    }
}

void NetworkManager::applyDTO(EntityDeletionDTO* dto) {
    std::cout << "Applying entity deletion" << std::endl;
    for (auto it = _idsToUuids.begin(); it != _idsToUuids.end(); ++it) {
        if (it->first == dto->getEntityId()) {
            ObjectManager::getInstance().removeObject(it->second);
            _idsToUuids.erase(it);
            break;
        }
    }
}

void NetworkManager::applyDTO(EntityPositionDTO* dto) {
    std::cout << "Applying entity position" << std::endl;
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

void NetworkManager::applyDTOs(std::vector<char> data) {
    std::cout << "Applying DTOs" << std::endl;
    IDTO* dto = _dtoDecoder->decode(data);

    if (dynamic_cast<EntityCreationDTO*>(dto) != nullptr) {
        applyDTO(dynamic_cast<EntityCreationDTO*>(dto));
    } else if (dynamic_cast<EntityDeletionDTO*>(dto) != nullptr) {
        applyDTO(dynamic_cast<EntityDeletionDTO*>(dto));
    } else if (dynamic_cast<EntityPositionDTO*>(dto) != nullptr) {
        applyDTO(dynamic_cast<EntityPositionDTO*>(dto));
    }
}

IComponent *NetworkManager::clone (IObject *owner) const {
    return nullptr;
}

void NetworkManager::deserialize(const json::IJsonObject *data) {}

void NetworkManager::end() {}

json::IJsonObject *NetworkManager::serializeData() {
    return nullptr;
}
