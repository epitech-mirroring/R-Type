/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Background.cpp
*/

#include "Background.hpp"

Background::Background(IObject *owner, const json::IJsonObject *data) : CPPMonoBehaviour(owner) {}

Transform *Background::getOwnerTransform() {
    for (auto &component : this->getOwner()->getComponents()) {
        if (component->getMeta().getName() == "Transform") {
            return dynamic_cast<Transform *>(component);
        }
    }
    return nullptr;
}

void Background::start() {
    startTime = clock();
    auto *transform = getOwnerTransform();
    transform->setPosition(Vector3(0, 0, 0));
}

void Background::update() {
    clock_t actualTime = clock();
    if ((actualTime - startTime) / CLOCKS_PER_SEC >= 0.10f / speed) {
        startTime = actualTime;
        auto *transform = getOwnerTransform();
        transform->setPosition(Vector3(transform->getPosition().x - 1, transform->getPosition().y, 0));
        if (transform->getPosition().x <= -1920)
            transform->setPosition(Vector3(0, transform->getPosition().y, 0));
    }
}

void Background::setSpeed(float newSpeed) {
    speed = newSpeed;
}

float Background::getSpeed() {
    return speed;
}

IComponent *Background::clone (IObject *owner) const {
    return nullptr;
}

void Background::deserialize(const json::IJsonObject *data) {}

void Background::end() {}

json::IJsonObject *Background::serializeData() {
    return nullptr;
}