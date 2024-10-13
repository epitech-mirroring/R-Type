/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.hpp
*/

#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include "common/components/CPPMonoBehaviour.hpp"
#include "common/components/Transform.hpp"
#include "common/event/EventSystem.hpp"
#include "common/managers/ObjectManager.hpp"
#include "common/json/JsonObject.hpp"

#include "../../dto/DTORegistry.hpp"
#include "../../dto/DTODecoder.hpp"
#include "../../dto/entity/EntityCreationDTO.hpp"
#include "../../dto/entity/EntityDeletionDTO.hpp"
#include "../../dto/entity/EntityPositionDTO.hpp"
#include "../../dto/entity/EntityTypeEnum.hpp"
#include "../../dto/player/PlayerActionEnum.hpp"
#include "../../dto/player/PlayerActionStartDTO.hpp"
#include "../../dto/player/PlayerActionStopDTO.hpp"

#include "../../network/client/Client.hpp"
#include "../../network/NetworkException.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>
#include <vector>
#include <iostream>

using JsonObject = json::JsonObject;

class NetworkManager final : public CPPMonoBehaviour {
public:
    NetworkManager(IObject *owner, const json::IJsonObject *data);
    ~NetworkManager() = default;

    void start();
    void update();
    void getEventData(EventData data);
    void applyDTO(EntityCreationDTO* dto);
    void applyDTO(EntityDeletionDTO* dto);
    void applyDTO(EntityPositionDTO* dto);
    void applyDTOs(std::vector<char> data, DTORegistry* dtoRegistry);

    IComponent *clone (IObject *owner) const override;
    void deserialize(const json::IJsonObject *data) override;
    void end() override;
    json::IJsonObject *serializeData() override;

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

#endif //NETWORKMANAGER_HPP
