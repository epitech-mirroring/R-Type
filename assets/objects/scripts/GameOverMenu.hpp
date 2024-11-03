/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameOverMenu.hpp
*/

#ifndef GAMEOVERMENU_HPP
#define GAMEOVERMENU_HPP

#include <string>

#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/event/EventSystem.hpp"
#include "StellarForge/Common/managers/ObjectManager.hpp"
#include "StellarForge/Common/managers/SceneManager.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"

#include <unordered_map>
#include <typeindex>
#include <vector>

class GameOverMenu final : public CPPMonoBehaviour {
public:
    GameOverMenu(IObject *owner, const json::JsonObject *data);
    ~GameOverMenu() override = default;

    void start() override;
    void update() override;

    static void quit(const EventData &data);
    static void reconnect(const EventData &data);

    IComponent *clone(IObject *owner) const override;
    void deserialize(const json::IJsonObject *data) override;
    void end() override;
    json::IJsonObject *serializeData() const override;

private:
};

#endif //GAMEOVERMENU_HPP
