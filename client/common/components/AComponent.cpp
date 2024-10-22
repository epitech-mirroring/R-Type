/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

#include "common/IObject.hpp"
#include "common/Utils.hpp"
#include "common/json/JsonBoolean.hpp"
#include "common/json/JsonObject.hpp"
#include "common/json/JsonString.hpp"

AComponent::AComponent(IObject *owner, const IMeta *meta,
                       const json::JsonObject *data): _owner(owner),
                                                      _meta(meta),
                                                      _isActive(true) {
    if (data != nullptr) {
        if (data->contains("isActive")) {
            this->_isActive = data->getValue<json::JsonBoolean>("isActive")->getValue();
        }
    }
}

AComponent::~AComponent() {
    delete this->_meta;
}

void AComponent::beforeRendering() {
}

void AComponent::afterRendering() {
}

IObject *AComponent::getOwner() {
    return this->_owner;
}

const IComponent::IMeta &AComponent::getMeta() const {
    return *this->_meta;
}

bool AComponent::isActive() {
    return this->_isActive;
}

void AComponent::setActive(const bool state) {
    this->_isActive = state;
}

void AComponent::onCreation() {
}

void AComponent::onDeletion() {
}



json::IJsonObject *AComponent::serialize() {
    auto *const obj = new json::JsonObject();
    obj->add(new json::JsonString(get_typename(this), "type")
    );
    obj->add(new json::JsonBoolean(this->_isActive, "isActive"));
    obj->add(this->serializeData());
    return obj;
}
