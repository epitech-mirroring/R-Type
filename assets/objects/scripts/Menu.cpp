/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

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

Menu::Menu(IObject *owner, const json::JsonObject *data)
    : CPPMonoBehaviour(owner, data) {
}

void Menu::start() {
    auto *title = getParentComponent<UIText>();
    if (title) {
        title->setFont("assets/objects/assets/arcade.ttf");
    }
    for (auto &component : getOwner()->getComponents()) {
        auto *button = dynamic_cast<UIButton *>(component);
        if (button) {
            button->setFont("assets/objects/assets/arcade.ttf");
        }
        auto *inputButton = dynamic_cast<UITextInputButton *>(component);
        if (inputButton) {
            EventSystem::getInstance().registerListener("button_" + inputButton->getButtonId() + "_stop_writing",
                [this](const EventData &data) {
                    this->stopInput(data);
                });
            EventSystem::getInstance().registerListener("button_" + inputButton->getButtonId() + "_start_writing",
                [this](const EventData &data) {
                    this->startInput(data);
                });
        }
        EventSystem::getInstance().registerListener("button_connect_pressed",
            [this](const EventData &data) {
                this->tryConnect(data);
            });
    }
}

bool Menu::endsWith(const std::string &str, const std::string &suffix) {
    if (str.length() >= suffix.length()) {
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    }
    return false;
}

void Menu::update() {
}

void Menu::resetMenu() {
    for (const auto &component : getOwner()->getComponents()) {
        if (auto *inputButton = dynamic_cast<UITextInputButton *>(component)) {
            inputButton->setLabel("");
        }
    }
}

bool Menu::isValidPort(const std::string& port) {
    if (port.empty() || port.length() > 5) {
        return false;
    }
    for (char const character : port) {
        if (std::isdigit(character) == 0) {
            return false;
        }
    }
    int const portNum = std::stoi(port);
    return portNum >= 0 && portNum <= 65535;
}

bool Menu::isValidIp(const std::string& ipStr) {
    int segments = 0;
    std::stringstream sStream(ipStr);
    std::string segment;

    while (std::getline(sStream, segment, '.')) {
        if (segment.empty() || segment.length() > 3) {
            return false;
        }
        for (char const character : segment) {
            if (std::isdigit(character) == 0) {
                return false;
            }
        }
        if (int const segmentNum = std::stoi(segment); segmentNum < 0 || segmentNum > 255) {
            return false;
        }
        segments++;
    }
    return segments == 4;
}

void Menu::connect(const std::string &ipStr, const int tcp_port, const int udp_port)
{
    UUID gameSceneUuid;
    gameSceneUuid.setUuidFromString("47cb9326-981a-4ee9-be57-aab7d7fc4f0e");
    const auto *gameScene = SceneManager::getInstance().getSceneById(gameSceneUuid);
    std::vector<IObject *> const objects = gameScene->getObjects();
    for (const auto &object : objects) {
        if (object->getMeta().getName() == "NetworkManager") {
            object->getComponent<NetworkManager>()->setConnexionInfos(ipStr, tcp_port, udp_port);
            std::cout << "Connected to " << ipStr << " on ports " << tcp_port << " and " << udp_port << std::endl;
            SceneManager::getInstance().switchToScene(gameSceneUuid);
            std::cout << "Switched to game scene" << std::endl;
            resetMenu();
            return;
        }
    }
    std::cerr << "Could not find NetworkManager" << std::endl;
}


void Menu::tryConnect(const EventData &data) {
    std::string ipStr;
    int tcp_port = 0;
    int udp_port = 0;

    for (const auto &component : getOwner()->getComponents()) {
        if (auto *inputButton = dynamic_cast<UITextInputButton *>(component)) {
            std::string const buttonId = inputButton->getButtonId();
            std::string const buttonText = inputButton->getLabel();
            if (endsWith(buttonId, "ip")) {
                if (isValidIp(buttonText)) {
                    ipStr = buttonText;
                } else {
                    inputButton->setTextColor(new sf::Color(255, 0, 0));
                    return;
                }
            } else if (endsWith(buttonId, "tcp_port")) {
                if (isValidPort(buttonText)) {
                    tcp_port = std::stoi(buttonText);
                } else {
                    inputButton->setTextColor(new sf::Color(255, 0, 0));
                    return;
                }
            } else if (endsWith(buttonId, "udp_port")) {
                if (isValidPort(buttonText)) {
                    udp_port = std::stoi(buttonText);
                } else {
                    inputButton->setTextColor(new sf::Color(255, 0, 0));
                    return;
                }
            }
        }
    }
    connect(ipStr, tcp_port, udp_port);
}

void Menu::startInput(const EventData &data) {
    for (const auto &component : getOwner()->getComponents()) {
        if (auto *inputButton = dynamic_cast<UITextInputButton *>(component)) {
            if (data.name == "button_" + inputButton->getButtonId() + "_start_writing") {
                inputButton->setTextColor(new sf::Color(200, 200, 200));
            }
        }
    }
}

void Menu::stopInput(const EventData &data) {
    for (const auto &component : getOwner()->getComponents()) {
        if (auto *inputButton = dynamic_cast<UITextInputButton *>(component)) {
            if (data.name == "button_" + inputButton->getButtonId() + "_stop_writing") {
                std::string const buttonId = inputButton->getButtonId();
                std::string const buttonText = inputButton->getLabel();

                if (endsWith(buttonId, "ip")) {
                    if (isValidIp(buttonText)) {
                        inputButton->setTextColor(new sf::Color(0, 255, 0));
                    } else {
                        inputButton->setTextColor(new sf::Color(255, 0, 0));
                    }
                } else if (endsWith(buttonId, "tcp_port") || endsWith(buttonId, "udp_port")) {
                    if (isValidPort(buttonText)) {
                        inputButton->setTextColor(new sf::Color(0, 255, 0));
                    } else {
                        inputButton->setTextColor(new sf::Color(255, 0, 0));
                    }
                } else {
                    inputButton->setTextColor(new sf::Color(0, 255, 0));
                }
            }
        }
    }
}

IComponent *Menu::clone(IObject *owner) const {
    auto *comp = new Menu(owner, nullptr);
    return comp;
}

void Menu::deserialize(const json::IJsonObject *data) {
}

void Menu::end() {
}

json::IJsonObject *Menu::serializeData() const {
    return new json::JsonNull();
}
