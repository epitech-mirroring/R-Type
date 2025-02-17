/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.cpp
*/

#include "NetworkManager.hpp"
#include "../network/protocol/dto/player/PlayerActionEnum.hpp"
#include "../network/protocol/dto/player/PlayerActionStartDTO.hpp"
#include "../network/protocol/dto/player/PlayerActionStopDTO.hpp"

#include <memory>


NetworkManager::NetworkManager(IObject *owner, const json::JsonObject *data)
    : CPPMonoBehaviour(owner, data) {
}

void NetworkManager::start() {
    const auto *gameScene = SceneManager::getInstance().getCurrentScene();
    std::vector<IObject *> const objects = gameScene->getObjects();
    for (const auto &object : objects)
    {
        if (object->getMeta().getName() == "NameTag")
        {
            for (auto *component: object->getComponents()) {
                if (component->getMeta().getName() == "UIText") {
                    auto *button = dynamic_cast<UIText *>(component);
                    button->setFont("assets/objects/assets/arcade.ttf");
                }
            }
        }
    }
    EventSystem::getInstance().registerListener("f2_pressed",
        [this](const EventData &data) {showArrows(data); });
}

void NetworkManager::showArrows(const EventData& data)
{
    _showArrows = !_showArrows;
    const auto *gameScene = SceneManager::getInstance().getCurrentScene();
    std::vector<IObject *> const objects = gameScene->getObjects();
    for (const auto &object : objects)
    {
        if (object->getMeta().getName() == "Arrows")
        {
            object->setActive(_showArrows);
        }
    }
}

void NetworkManager::setConnexionInfos(const std::string &ipStr, const int tcp_port, const int udp_port) {
    _ip = ipStr;
    _tcp_port = tcp_port;
    _udp_port = udp_port;
}

void NetworkManager::setConnected(const bool isConnected) {
    _isConnected = isConnected;
}

void NetworkManager::update() {
    if (!_isConnected) {
        _client = std::make_shared<Network::Client>(_ip, _udp_port, _tcp_port);
        _dtoRegistry = new DTORegistry();
        _dtoEncoder = new DTOEncoder(_dtoRegistry);
        _dtoDecoder = new DTODecoder(_dtoRegistry);
        try {
            _client->connect();
            auto *audio = getParentComponent<AudioSource>();
            audio->play();
        } catch (const NetworkException &e) {
            UUID menuSceneUuid;
            menuSceneUuid.setUuidFromString("89de1e2b-3599-4416-b0ee-c03d2f9e4e82");
            SceneManager::getInstance().switchToScene(menuSceneUuid);
            return;
        }

        _playerId = _client->getId();

        EventSystem::getInstance().registerListener("z_pressed",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("z_released",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("s_pressed",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("s_released",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("q_pressed",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("q_released",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("d_pressed",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("d_released",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("space_pressed",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("space_released",
                                                    [this](const EventData &data) {
                                                        getEventData(data);
                                                    });
        EventSystem::getInstance().registerListener("add_pressed",
                                                    [this](const EventData &data) {
                                                        sendGameSpeedUpdate(data);
                                                    });
        EventSystem::getInstance().registerListener("subtract_pressed",
                                                    [this](const EventData &data) {
                                                        sendGameSpeedUpdate(data);
                                                    });
        _isConnected = true;
    }
    if (!this->_client->is_alive()) {
        std::cout << "The connection has been lost" << '\n';
        EventSystem::getInstance().triggerEvents("window_closed");
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
    for (auto &idUuidPair: _idsToUuids) {
        IObject *object = ObjectManager::getInstance().getObjectById(idUuidPair.second);
        Transform *transform = nullptr;
        if (object == nullptr) {
            continue;
        }
        for (auto *component: object->getComponents()) {
            if (component->getMeta().getName() == "Transform") {
                transform = dynamic_cast<Transform *>(component);
                break;
            }
        }
        if (transform == nullptr) {
            continue;
        }
        if (_entities[idUuidPair.second] == EntityType::PLAYER) {
            continue;
        }
        if (transform->getPosition().x < 0 || transform->getPosition().x > 1920 ||
            transform->getPosition().y < 0 || transform->getPosition().y > 1080) {
            ObjectManager::getInstance().getObjectById(idUuidPair.second)->setActive(
                false);
            SceneManager::getInstance().getCurrentScene()->removeObject(
                ObjectManager::getInstance().getObjectById(idUuidPair.second));
            ObjectManager::getInstance().removeObject(idUuidPair.second);
            _idsToUuids.erase(std::remove_if(_idsToUuids.begin(), _idsToUuids.end(),
                                             [idUuidPair](
                                         std::pair<int, UUID> const &pair) {
                                                 return pair.first == idUuidPair.first;
                                             }), _idsToUuids.end());
            _entities.erase(idUuidPair.second);
        }
    }
}

void NetworkManager::getEventData(const EventData &data) {
    if (_playerId == -1) {
        return;
    }
    std::string const name = data.name;
    PlayerAction action = PlayerAction::NO_ACTION;

    std::string const key = name.substr(0, name.find('_'));
    std::string const actionName = name.substr(name.find('_') + 1, name.size());

    if (key == "z") {
        action = PlayerAction::MOVE_UP;
    } else if (key == "s") {
        action = PlayerAction::MOVE_DOWN;
    } else if (key == "q") {
        action = PlayerAction::MOVE_LEFT;
    } else if (key == "d") {
        action = PlayerAction::MOVE_RIGHT;
    } else if (key == "space") {
        action = PlayerAction::SHOOT;
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

void NetworkManager::sendGameSpeedUpdate(const EventData &data) const
{
    if (_playerId == -1) {
        return;
    }
    GameSpeedEnum speed = NO_CHANGE;

    if (data.name == "add_pressed") {
        speed = FASTER;
    } else if (data.name == "subtract_pressed") {
        speed = SLOWER;
    }

    auto dto = GameSpeedDTO(speed);
    _client->send_udp_data(_dtoEncoder->encode(dto));
}

void NetworkManager::applyDTO(EntityCreationDTO *dto) {
    UUID baseUuid;
    std::string baseUuidStr;
    for (auto &entityTypeUuid: _entityTypesUuids) {
        if (entityTypeUuid.first == dto->getEntityType()) {
            baseUuidStr = entityTypeUuid.second;
            break;
        }
    }
    if (dto->getEntityId() == _playerId) {
        baseUuidStr = "d9e329e7-b3bf-412e-86a5-f8e18f710756";
    }

    if (baseUuidStr.empty()) {
        std::cerr << "Unknown entity type" << '\n';
        return;
    }

    baseUuid.setUuidFromString(baseUuidStr);
    UUID const uuid = ObjectManager::getInstance().duplicateObject(baseUuid);
    IObject *object = ObjectManager::getInstance().getObjectById(uuid);
    object->setActive(true);
    ObjectManager::getInstance().updateObject(uuid, object);
    for (auto *component: object->getComponents()) {
        if (component->getMeta().getName() == "Transform") {
            auto *transform = dynamic_cast<Transform *>(component);
            transform->setPosition(glm::vec3(dto->getPosX(), dto->getPosY(), 0));
            break;
        }
    }
    _idsToUuids.emplace_back(dto->getEntityId(), uuid);
    if (dto->getEntityId() == _playerId) {
        _playerUuid = uuid;
    }
    _entities.emplace(uuid, dto->getEntityType());
}

void NetworkManager::applyDTO(EntityDeletionDTO *dto) {
    std::cout << "Deleting entity with id: " << dto->getEntityId() << '\n';
    for (auto it = _idsToUuids.begin(); it != _idsToUuids.end(); ++it) {
        if (it->first == dto->getEntityId()) {
            if (ObjectManager::getInstance().getObjectById(it->second) == nullptr) {
                continue;
            }
            ObjectManager::getInstance().getObjectById(it->second)->setActive(false);
            SceneManager::getInstance().getCurrentScene()->removeObject(
                ObjectManager::getInstance().getObjectById(it->second));
            ObjectManager::getInstance().removeObject(it->second);
            _idsToUuids.erase(it);
            _entities.erase(it->second);
            break;
        }
    }
    if (dto->getEntityId() == _playerId) {
        gameOver();
    }
}

void NetworkManager::gameOver() {
    for (auto & [fst, snd]: _idsToUuids) {
        auto *obj = ObjectManager::getInstance().getObjectById(snd);
        if (obj == nullptr) {
            continue;
        }
        obj->setActive(false);
        SceneManager::getInstance().getCurrentScene()->removeObject(obj);
        ObjectManager::getInstance().removeObject(snd);
    }
    auto *audio = getParentComponent<AudioSource>();
    audio->stop();

    UUID gameOverMenuSceneUuid;
    gameOverMenuSceneUuid.setUuidFromString("d0b63cc4-eb6f-4459-90f2-e7daaef61814");
    const auto *gameOverMenuScene = SceneManager::getInstance().getSceneById(gameOverMenuSceneUuid);
    for (const auto *object: gameOverMenuScene->getObjects()) {
        if (object->getMeta().getName() == "GameOverMenu") {
            for (auto *component: object->getComponents()) {
                if (component->getMeta().getName() == "AudioSource") {
                    auto *audio = dynamic_cast<AudioSource *>(component);
                    audio->play();
                }
            }
        }
    }
    SceneManager::getInstance().switchToScene(gameOverMenuSceneUuid);
}


void NetworkManager::applyDTO(EntityPositionDTO *dto) {
    if (_playerId == -1) {
        return;
    }
    bool found = false;

    for (auto &idUuidPair: _idsToUuids) {
        if (idUuidPair.first == dto->getEntityId()) {
            IObject *object = ObjectManager::getInstance().getObjectById(
                idUuidPair.second);
            Transform *transform = nullptr;
            if (object == nullptr) {
                continue;
            }
            for (auto *component: object->getComponents()) {
                if (component->getMeta().getName() == "Transform") {
                    transform = dynamic_cast<Transform *>(component);
                    transform->setPosition(glm::vec3(dto->getPosX(), dto->getPosY(), transform->getPosition().z));
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found) {
        applyDTO(new EntityCreationDTO(dto->getEntityId(), dto->getEntityType(),
                                       dto->getPosX(), dto->getPosY()));
    }
    if (dto->getEntityId() == _playerId) {
        const auto *gameScene = SceneManager::getInstance().getCurrentScene();
        std::vector<IObject *> const objects = gameScene->getObjects();
        for (const auto &object : objects)
        {
            if (object->getMeta().getName() == "NameTag") {
                for (auto *component: object->getComponents()) {
                    if (component->getMeta().getName() == "Transform") {
                        auto *transform = dynamic_cast<Transform *>(component);
                        transform->setPosition(glm::vec3(dto->getPosX() + 50, dto->getPosY() - 50, 0));
                        break;
                    }
                }
            }
        }
    }
}

void NetworkManager::applyDTO(const GameSpeedDTO *dto) {
    std::cout << "Game speed ";
    switch (dto->getSpeed())
    {
    case FASTER:
        std::cout << "was increased" << '\n';
        break;
    case SLOWER:
        std::cout << "was decreased" << '\n';
        break;
    default:
        std::cout << "was not changed" << '\n';
        break;
    }
}

void NetworkManager::applyDTOs(std::vector<char> data) {
    IDTO *dto = _dtoDecoder->decode(data);

    if (dynamic_cast<EntityCreationDTO *>(dto) != nullptr) {
        applyDTO(dynamic_cast<EntityCreationDTO *>(dto));
    } else if (dynamic_cast<EntityDeletionDTO *>(dto) != nullptr) {
        applyDTO(dynamic_cast<EntityDeletionDTO *>(dto));
    } else if (dynamic_cast<EntityPositionDTO *>(dto) != nullptr) {
        applyDTO(dynamic_cast<EntityPositionDTO *>(dto));
    } else if (dynamic_cast<GameSpeedDTO *>(dto) != nullptr) {;
        applyDTO(dynamic_cast<GameSpeedDTO *>(dto));
    }
}

IComponent *NetworkManager::clone(IObject *owner) const {
    auto *comp = new NetworkManager(owner, nullptr);
    return comp;
}

void NetworkManager::deserialize(const json::IJsonObject *data) {
}

void NetworkManager::end() {
}

json::IJsonObject *NetworkManager::serializeData() const {
    return nullptr;
}
