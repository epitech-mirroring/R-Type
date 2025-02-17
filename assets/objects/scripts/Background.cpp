/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Background.cpp
*/

#include "Background.hpp"

#include <StellarForge/Common/event/EventSystem.hpp>

Background::Background(IObject *owner, const json::JsonObject *data) :
    CPPMonoBehaviour(owner, data) {}

void Background::start() {
    startTime = std::chrono::high_resolution_clock::now();
    actualTime = std::chrono::high_resolution_clock::now();
    auto *transform = getParentComponent<Transform>();
    transform->setPosition(glm::vec3(0, 0, 0));
    EventSystem::getInstance().registerListener("f1_pressed", [this](const EventData &data) {
        (void)data;
        isActive = !isActive;
    });
}

void Background::update() {
    if (!isActive) {
        return;
    }
    actualTime = std::chrono::high_resolution_clock::now();
    if (std::chrono::duration<float, std::chrono::seconds::period>(actualTime - startTime).count() >= 0.01f) {
        auto *transform = getParentComponent<Transform>();
        transform->setPosition(glm::vec3(transform->getPosition().x - 5, transform->getPosition().y, -10));
        if (transform->getPosition().x <= -1920) {
            transform->setPosition(glm::vec3(0, transform->getPosition().y, -10));
        }
        startTime = actualTime;
    }
}

void Background::setSpeed(float newSpeed) {
    speed = newSpeed;
}

float Background::getSpeed() const {
    return speed;
}

IComponent *Background::clone (IObject *owner) const {
    auto *comp = new Background(owner, nullptr);
    comp->speed = speed;
    return comp;
}

void Background::deserialize(const json::IJsonObject *data) {}

void Background::end() {}

json::IJsonObject *Background::serializeData() const {
    return nullptr;
}
