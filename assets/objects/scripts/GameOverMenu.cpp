/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameOverMenu.cpp
*/

#include "GameOverMenu.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <regex>

#include "NetworkManager.hpp"

#include "StellarForge/Common/json/JsonNull.hpp"
#include "StellarForge/Graphics/components/UIText.hpp"
#include "StellarForge/Graphics/components/UITextInputButton.hpp"
#include "StellarForge/Graphics/components/UIButton.hpp"

#include "StellarForge/Common/event/EventSystem.hpp"

GameOverMenu::GameOverMenu(IObject *owner, const json::JsonObject *data)
    : CPPMonoBehaviour(owner, data) {
}

void GameOverMenu::start() {
    auto *title = getParentComponent<UIText>();
    if (title) {
        title->setFont("assets/objects/assets/arcade.ttf");
    }
    for (auto &component : getOwner()->getComponents())
    {
        auto *button = dynamic_cast<UIButton *>(component);
        if (button) {
            button->setFont("assets/objects/assets/arcade.ttf");
        }
    }
    EventSystem::getInstance().registerListener("button_reconnect_pressed",
            [this](const EventData &data) {
                this->reconnect(data);
            });
    EventSystem::getInstance().registerListener("button_quit_pressed",
            [this](const EventData &data) {
                this->quit(data);
            });
}

void GameOverMenu::update() {
}

void GameOverMenu::quit(const EventData &data) {
    EventSystem::getInstance().triggerEvents("window_closed", nullptr);
}

void GameOverMenu::reconnect(const EventData &data) {
    UUID gameSceneUuid;
    gameSceneUuid.setUuidFromString("47cb9326-981a-4ee9-be57-aab7d7fc4f0e");
    const auto *gameScene = SceneManager::getInstance().getSceneById(gameSceneUuid);
    std::vector<IObject *> const objects = gameScene->getObjects();
    for (const auto &object : objects) {
        if (object->getMeta().getName() == "NetworkManager") {
            object->getComponent<NetworkManager>()->setConnected(false);
            SceneManager::getInstance().switchToScene(gameSceneUuid);
            std::cout << "Switched to game scene" << std::endl;
            return;
        }
    }
    std::cerr << "Could not find NetworkManager" << std::endl;
}

IComponent *GameOverMenu::clone(IObject *owner) const {
    auto *comp = new GameOverMenu(owner, nullptr);
    return comp;
}

void GameOverMenu::deserialize(const json::IJsonObject *data) {
}

void GameOverMenu::end() {
}

json::IJsonObject *GameOverMenu::serializeData() const {
    return new json::JsonNull();
}
