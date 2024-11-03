/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Arrows.cpp
*/

#include "Arrows.hpp"

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

Arrows::Arrows(IObject *owner, const json::JsonObject *data)
    : CPPMonoBehaviour(owner, data) {
}

void Arrows::manageArrows(const EventData &data) {
    if (data.name == "button_shoot_pressed") {
        _isFiring = !_isFiring;
        if (_isFiring) {
            EventSystem::getInstance().triggerEvents("space_pressed", nullptr);
        } else {
            EventSystem::getInstance().triggerEvents("space_released", nullptr);
        }
    }
    if (data.name == "button_up_pressed") {
        EventSystem::getInstance().triggerEvents("z_pressed", nullptr);
    }
    if (data.name == "button_down_pressed") {
        EventSystem::getInstance().triggerEvents("s_pressed", nullptr);
    }
    if (data.name == "button_left_pressed") {
        EventSystem::getInstance().triggerEvents("q_pressed", nullptr);
    }
    if (data.name == "button_right_pressed") {
        EventSystem::getInstance().triggerEvents("d_pressed", nullptr);
    }
    if (data.name == "button_up_released") {
        EventSystem::getInstance().triggerEvents("z_released", nullptr);
    }
    if (data.name == "button_down_released") {
        EventSystem::getInstance().triggerEvents("s_released", nullptr);
    }
    if (data.name == "button_left_released") {
        EventSystem::getInstance().triggerEvents("q_released", nullptr);
    }
    if (data.name == "button_right_released") {
        EventSystem::getInstance().triggerEvents("d_released", nullptr);
    }
}

void Arrows::start() {
    for (const auto &component : getOwner()->getComponents()) {
        if (auto *button = dynamic_cast<UIButton *>(component)) {
            button->setFont("assets/objects/assets/arcade.ttf");
            EventSystem::getInstance().registerListener("button_" + button->getButtonId() + "_pressed",
            [this](const EventData &data) {
                this->manageArrows(data);
            });
            EventSystem::getInstance().registerListener("button_" + button->getButtonId() + "_released",
                [this](const EventData &data) {
                    this->manageArrows(data);
                });
        }
    }
}

void Arrows::update() {
}

IComponent *Arrows::clone(IObject *owner) const {
    auto *comp = new Arrows(owner, nullptr);
    return comp;
}

void Arrows::deserialize(const json::IJsonObject *data) {
}

void Arrows::end() {
}

json::IJsonObject *Arrows::serializeData() const {
    return new json::JsonNull();
}
