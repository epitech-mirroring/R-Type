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
#include "common/managers/SceneManager.hpp"
#include "common/json/JsonObject.hpp"

#include "../../client/dto/DTORegistry.hpp"
#include "../../client/dto/DTODecoder.hpp"
#include "../../client/dto/DTOEncoder.hpp"
#include "../../client/dto/entity/EntityCreationDTO.hpp"
#include "../../client/dto/entity/EntityDeletionDTO.hpp"
#include "../../client/dto/entity/EntityPositionDTO.hpp"
#include "../../client/dto/entity/EntityTypeEnum.hpp"
#include "../../client/dto/player/PlayerActionEnum.hpp"
#include "../../client/dto/player/PlayerActionStartDTO.hpp"
#include "../../client/dto/player/PlayerActionStopDTO.hpp"

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
    NetworkManager(IObject *owner, const json::JsonObject *data);
    ~NetworkManager() override = default;

    void start() override;
    void update() override;
    void getEventData(const EventData& data);
    void applyDTO(EntityCreationDTO* dto);
    void applyDTO(EntityDeletionDTO* dto);
    void applyDTO(EntityPositionDTO* dto);
    void applyDTOs(std::vector<char> data);

    void checkEntitiesOutOfBound();

    IComponent *clone (IObject *owner) const override;
    void deserialize(const json::IJsonObject *data) override;
    void end() override;
    json::IJsonObject *serializeData() override;

private:
    std::shared_ptr<Network::Client> _client = nullptr;
    DTORegistry* _dtoRegistry = nullptr;
    DTOEncoder* _dtoEncoder{};
    DTODecoder* _dtoDecoder{};
    int _playerId = -1;
    UUID _playerUuid;
    std::vector<std::pair<int, UUID>> _idsToUuids = {};
    std::vector<std::pair<EntityType, std::string>> _entityTypesUuids = {
        {EntityType::PLAYER, "9f19e43c-990b-4314-a039-d729a1dab876"},
        {EntityType::ENEMY, "9a24f7e2-edbb-4e54-a5dc-944454c8c1fd"},
        {EntityType::BULLET, "0276701c-58fd-4d88-ade0-25aac4ab905b"}
    };
    bool _isConnected = false;
    std::unordered_map<UUID, EntityType> _entities;
};

#endif //NETWORKMANAGER_HPP
