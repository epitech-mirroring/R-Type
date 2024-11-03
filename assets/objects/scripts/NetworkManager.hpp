/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** NetworkManager.hpp
*/

#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/components/Transform.hpp"
#include "StellarForge/Common/event/EventSystem.hpp"
#include "StellarForge/Common/managers/ObjectManager.hpp"
#include "StellarForge/Common/managers/SceneManager.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"
#include "../network/protocol/dto/DTORegistry.hpp"
#include "../network/protocol/dto/DTODecoder.hpp"
#include "../network/protocol/dto/DTOEncoder.hpp"
#include "../network/protocol/dto/entity/EntityCreationDTO.hpp"
#include "../network/protocol/dto/entity/EntityDeletionDTO.hpp"
#include "../network/protocol/dto/entity/EntityPositionDTO.hpp"
#include "../network/protocol/dto/entity/EntityTypeEnum.hpp"
#include "../network/protocol/dto/player/PlayerActionEnum.hpp"
#include "../network/protocol/dto/player/PlayerActionStartDTO.hpp"
#include "../network/protocol/dto/player/PlayerActionStopDTO.hpp"
#include "../network/protocol/dto/game/GameSpeedDTO.hpp"
#include "../network/client/Client.hpp"
#include "../network/NetworkException.hpp"

#include <unordered_map>
#include <typeindex>
#include <vector>

using JsonObject = json::JsonObject;

class NetworkManager final : public CPPMonoBehaviour {
public:
    NetworkManager(IObject *owner, const json::JsonObject *data);

    ~NetworkManager() override = default;

    void start() override;

    void update() override;

    void getEventData(const EventData &data);

    void sendGameSpeedUpdate(const EventData &data) const;

    void applyDTO(EntityCreationDTO *dto);

    void applyDTO(EntityDeletionDTO *dto);

    void applyDTO(EntityPositionDTO *dto);

    void applyDTO(const GameSpeedDTO *dto);

    void applyDTOs(std::vector<char> data);

    void checkEntitiesOutOfBound();

    IComponent *clone(IObject *owner) const override;

    void deserialize(const json::IJsonObject *data) override;

    void end() override;

    json::IJsonObject *serializeData() override;

private:
    std::shared_ptr<Network::Client> _client = nullptr;
    DTORegistry *_dtoRegistry = nullptr;
    DTOEncoder *_dtoEncoder{};
    DTODecoder *_dtoDecoder{};
    int _playerId = -1;
    UUID _playerUuid;
    std::vector<std::pair<int, UUID> > _idsToUuids = {};
    std::vector<std::pair<EntityType, std::string> > _entityTypesUuids = {
        {EntityType::PLAYER, "9f19e43c-990b-4314-a039-d729a1dab876"},
        {EntityType::ENEMY, "9a24f7e2-edbb-4e54-a5dc-944454c8c1fd"},
        {EntityType::BULLET, "0276701c-58fd-4d88-ade0-25aac4ab905b"}
    };
    bool _isConnected = false;
    std::unordered_map<UUID, EntityType> _entities;
};

#endif //NETWORKMANAGER_HPP
