/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** SpriteSheet.cpp
**/

#include <SFML/Graphics/Rect.hpp>
#include "SpriteSheet.hpp"
#include "Sprite.hpp"
#include "common/components/AComponent.hpp"
#include "common/components/Transform.hpp"
#include "common/fields/FileField.hpp"
#include "common/json/JsonNumber.hpp"
#include "common/json/JsonString.hpp"
#include "graphics/GraphicsException.hpp"

SpriteSheet::SpriteSheet(IObject *owner, const std::string &path,
                         const std::vector<sf::IntRect> &frames,
                         const unsigned int frame) : AComponent(owner, new Meta(this)),
                                                     frames(frames),
                                                     currentFrame(frame), path(path) {
    if (!texture.loadFromFile(path)) {
        throw GraphicsException("Failed to load texture from file: " + std::string(path));
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(frames[currentFrame]);
}

SpriteSheet::SpriteSheet(IObject *owner, const json::JsonObject *data): AComponent(
        owner, new Meta(this), data), frames({}), currentFrame(0) {
}


void SpriteSheet::render(sf::RenderWindow *window) {
    const auto *transformComponent = getParentComponent<Transform>();
    if (transformComponent != nullptr) {
        sprite.setPosition(transformComponent->getPosition().x,
                           transformComponent->getPosition().y);
        sprite.setRotation(transformComponent->getRotation().x);
        sprite.setScale(transformComponent->getScale().x,
                        transformComponent->getScale().y);
        sprite.setTextureRect(frames[currentFrame]);
        window->draw(sprite);
    }
}

void SpriteSheet::setTexture(const std::string &path) {
    if (!texture.loadFromFile(path)) {
        throw GraphicsException("Failed to load texture from file: " + std::string(path));
    }
    sprite.setTexture(texture);
}

void SpriteSheet::setFrames(std::vector<sf::IntRect> frames) {
    this->frames = std::move(frames);
}

void SpriteSheet::setFrame(const unsigned int frame) {
    currentFrame = frame;
    sprite.setTextureRect(frames[currentFrame]);
}

void SpriteSheet::nextFrame() {
    currentFrame++;
    if (currentFrame >= frames.size()) {
        currentFrame = 0;
    }
    sprite.setTextureRect(frames[currentFrame]);
}

void SpriteSheet::prevFrame() {
    currentFrame--;
    if (currentFrame < 0) {
        currentFrame = static_cast<unsigned int>(frames.size()) - 1;
    }
    sprite.setTextureRect(frames[currentFrame]);
}

glm::vec2 SpriteSheet::getSize() {
    return {frames[currentFrame].width, frames[currentFrame].height};
}

void SpriteSheet::runComponent() {
}

SpriteSheet::Meta::Meta(SpriteSheet *owner): IMeta(), _owner(owner), _fieldGroup({}) {
    auto fields = std::vector<IField *>();
    fields.push_back(new FileField("Sprite", "Path to the sprite sheet image"));
    _fieldGroup = InvisibleFieldGroup(fields);
}

std::string SpriteSheet::Meta::getName() const {
    return "SpriteSheet";
}

std::string SpriteSheet::Meta::getDescription() const {
    return "A sprite sheet component that renders a sprite sheet on the screen";
}

bool SpriteSheet::Meta::isUnique() const {
    return false;
}

bool SpriteSheet::Meta::canBeRemoved() const {
    return true;
}

std::vector<const IComponent::IMeta::IFieldGroup *>
SpriteSheet::Meta::getFieldGroups() const {
    return {&_fieldGroup};
}

json::IJsonObject *SpriteSheet::serializeData() {
    auto *const data = new json::JsonObject("data");
    data->add(new json::JsonString(path, "path"));
    data->add(new json::JsonNumber(static_cast<int>(currentFrame), "currentFrame"));
    return data;
}

void SpriteSheet::deserialize(const json::IJsonObject *data) {
    if (data != nullptr && data->getType() == json::OBJECT) {
        const auto *obj = dynamic_cast<const json::JsonObject *>(data);
        if (obj->contains("path")) {
            path = obj->getValue<json::JsonString>("path")->getValue();
            setTexture(path);
        }
        if (obj->contains("currentFrame")) {
            currentFrame = obj->getValue<json::JsonNumber>("currentFrame")->getIntValue();
        }
    }
}

SpriteSheet *SpriteSheet::clone(IObject *owner) const {
    return new SpriteSheet(owner, path, frames, currentFrame);
}
