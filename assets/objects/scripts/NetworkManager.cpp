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
}

void NetworkManager::update() {
    if (!_isConnected)
    {
        _client = std::make_shared<Network::Client>("127.0.0.1", 4445, 4444); // TODO get from config
        _dtoRegistry = new DTORegistry();
        _dtoEncoder = new DTOEncoder(_dtoRegistry);
        _dtoDecoder = new DTODecoder(_dtoRegistry);
        try {
            _client->connect();
        } catch (const NetworkException& e) {
            std::cerr << "Failed to connect to server: " << e.what() << std::endl;
            return;
        }

        _playerId = _client->getId();

        EventSystem::getInstance().registerListener("z_pressed", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("z_released", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("s_pressed", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("s_released", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("q_pressed", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("q_released", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("d_pressed", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("d_released", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("space_pressed", [this](const EventData& data) {
            getEventData(data);
        });
        EventSystem::getInstance().registerListener("space_released", [this](const EventData& data) {
            getEventData(data);
        });
        _isConnected = true;
    }
    while (_client->get_size_recv_queue() > 0) {
        std::vector<char> const data = _client->get_next_recv_queue();
        if (data.empty()) {
            return;
        }
        applyDTOs(data);
    }
    checkEntitiesOutOfBound();
}

void NetworkManager::checkEntitiesOutOfBound() {
    for (auto& idUuidPair : _idsToUuids) {
        IObject* object = ObjectManager::getInstance().getObjectById(idUuidPair.second);
        Transform* transform = nullptr;
        if (object == nullptr) {
            continue;
        }
        for (auto *component : object->getComponents()) {
            if (component->getMeta().getName() == "Transform") {
                transform = dynamic_cast<Transform*>(component);
                break;
            }
        }
        if (transform == nullptr) {
            continue;
        }
        if (_entities[idUuidPair.second] == EntityType::PLAYER) {
            continue;
        }
        if (transform->getPosition().x < 0 || transform->getPosition().x > 1920 || transform->getPosition().y < 0 || transform->getPosition().y > 1080) {
            std::cout << "remove object" << std::endl;
            ObjectManager::getInstance().getObjectById(idUuidPair.second)->setActive(false);
            SceneManager::getInstance().getCurrentScene()->removeObject(ObjectManager::getInstance().getObjectById(idUuidPair.second));
            ObjectManager::getInstance().removeObject(idUuidPair.second);
            _idsToUuids.erase(std::remove_if(_idsToUuids.begin(), _idsToUuids.end(), [idUuidPair](std::pair<int, UUID> const& pair) {
                return pair.first == idUuidPair.first;
            }), _idsToUuids.end());
            _entities.erase(idUuidPair.second);
        }
    }
}

void NetworkManager::getEventData(const EventData& data) {

    if (_playerId == -1) {
        return;
    }
    std::string const name = data.name;
    PlayerAction action = PlayerAction::NO_ACTION;

    std::string const key = name.substr(0, name.find('_'));
    std::string const actionName = name.substr(name.find('_') + 1, name.size());

    if (key == "z") {
        action = PlayerAction::MOVE_UP;
    } else if (key == "s") { action = PlayerAction::MOVE_DOWN;
    } else if (key == "q") { action = PlayerAction::MOVE_LEFT;
    } else if (key == "d") { action = PlayerAction::MOVE_RIGHT;
    } else if (key == "space") { action = PlayerAction::SHOOT;
    }

    if (actionName == "pressed") {
        PlayerActionStartDTO dto;
        dto.setPlayerId(_playerId);
        dto.setAction(action);
        _client->send_udp_data(_dtoEncoder->encode(dto));
    } else if (actionName == "released") {
        PlayerActionStopDTO dto;
        dto.setPlayerId(_playerId);
        dto.setAction(action);
        _client->send_udp_data(_dtoEncoder->encode(dto));
    }
}

void NetworkManager::applyDTO(EntityCreationDTO* dto) {
    UUID baseUuid;
    std::string baseUuidStr;
    for (auto& entityTypeUuid : _entityTypesUuids) {
        if (entityTypeUuid.first == dto->getEntityType()) {
            baseUuidStr = entityTypeUuid.second;
            break;
        }
    }
    if (dto->getEntityId() == _playerId) {
        baseUuidStr = "d9e329e7-b3bf-412e-86a5-f8e18f710756"; // TODO: get from config
    }

    if (baseUuidStr.empty()) {
        std::cerr << "Unknown entity type" << std::endl;
        return;
    }

    baseUuid.setUuidFromString(baseUuidStr);
    UUID const uuid = ObjectManager::getInstance().duplicateObject(baseUuid);
    IObject* object = ObjectManager::getInstance().getObjectById(uuid);
    object->setActive(true);
    ObjectManager::getInstance().updateObject(uuid, object);
    for (auto *component : object->getComponents()) {
        if (component->getMeta().getName() == "Transform") {
            auto* transform = dynamic_cast<Transform*>(component);
            transform->setPosition(Vector3(dto->getPosX(), dto->getPosY(), 0));
            break;
        }
    }
    _idsToUuids.emplace_back(dto->getEntityId(), uuid);
    if (dto->getEntityId() == _playerId) {
        _playerUuid = uuid;
    }
    _entities.emplace(uuid, dto->getEntityType());
}

void NetworkManager::applyDTO(EntityDeletionDTO* dto) {
    std::cout << "Deleting entity with id: " << dto->getEntityId() << std::endl;
    for (auto it = _idsToUuids.begin(); it != _idsToUuids.end(); ++it) {
        if (it->first == dto->getEntityId()) {
            if (ObjectManager::getInstance().getObjectById(it->second) == nullptr) {
                continue;
            }
            ObjectManager::getInstance().getObjectById(it->second)->setActive(false);
            SceneManager::getInstance().getCurrentScene()->removeObject(ObjectManager::getInstance().getObjectById(it->second));
            ObjectManager::getInstance().removeObject(it->second);
            _idsToUuids.erase(it);
            _entities.erase(it->second);
            break;
        }
    }
}

void NetworkManager::applyDTO(EntityPositionDTO* dto) {
    if (_playerId == -1) {
        return;
    }
    bool found = false;

    for (auto& idUuidPair : _idsToUuids) {
        if (idUuidPair.first == dto->getEntityId()) {
            IObject* object = ObjectManager::getInstance().getObjectById(idUuidPair.second);
            Transform* transform = nullptr;
            if (object == nullptr) {
                continue;
            }
            for (auto *component : object->getComponents()) {
                if (component->getMeta().getName() == "Transform") {
                    transform = dynamic_cast<Transform*>(component);
                    transform->setPosition(Vector3(dto->getPosX(), dto->getPosY(), 0));
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found) {
        applyDTO(new EntityCreationDTO(dto->getEntityId(), dto->getEntityType(), dto->getPosX(), dto->getPosY()));
    }
}

void NetworkManager::applyDTOs(std::vector<char> data) {
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
    auto *comp = new NetworkManager(owner, nullptr);
    return comp;
}

void NetworkManager::deserialize(const json::IJsonObject *data) {}

void NetworkManager::end() {}

json::IJsonObject *NetworkManager::serializeData() {
    return nullptr;
}
