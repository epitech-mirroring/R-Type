/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** AnimatedSprite.cpp
**/

#include "AnimatedSprite.hpp"

#include "common/components/Transform.hpp"
#include "common/fields/FileField.hpp"
#include "common/json/JsonArray.hpp"
#include "common/json/JsonNumber.hpp"
#include "common/json/JsonString.hpp"
#include "graphics/GraphicsException.hpp"

AnimatedSprite::AnimatedSprite(IObject *owner, const std::string &path,
                               const std::vector<sf::IntRect> &frames,
                               const float frameTime,
                               const unsigned int currentFrame)
    : AComponent(owner, new Meta(this)), frames(frames), currentFrame(currentFrame),
      frameTime(frameTime),
      path(path) {
    if (!texture.loadFromFile(path)) {
        throw GraphicsException("Failed to load texture from file: " + std::string(path));
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(frames[currentFrame]);
}

AnimatedSprite::AnimatedSprite(IObject *owner, const json::JsonObject *data): AComponent(
        owner, new Meta(this), data), frames({}), currentFrame(0), frameTime(0.1f) {
}


void AnimatedSprite::runComponent() {
    if (clock.getElapsedTime().asSeconds() >= frameTime) {
        nextFrame();
        clock.restart();
    }
}

void AnimatedSprite::render(sf::RenderWindow *window) {
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

void AnimatedSprite::setTexture(const std::string &path) {
    if (!texture.loadFromFile(path)) {
        throw GraphicsException("Failed to load texture from file: " + std::string(path));
    }
    sprite.setTexture(texture);
}

void AnimatedSprite::setFrames(std::vector<sf::IntRect> frames) {
    this->frames = std::move(frames);
}

void AnimatedSprite::setFrame(const unsigned int frame) {
    if (frame >= frames.size()) {
        throw GraphicsException("Frame index out of range");
    }
    currentFrame = frame;
    sprite.setTextureRect(frames[currentFrame]);
}

void AnimatedSprite::nextFrame() {
    currentFrame++;
    if (currentFrame >= frames.size()) {
        currentFrame = 0;
    }
    sprite.setTextureRect(frames[currentFrame]);
}

void AnimatedSprite::prevFrame() {
    currentFrame--;
    if (currentFrame < 0) {
        currentFrame = static_cast<unsigned int>(frames.size()) - 1;
    }
    sprite.setTextureRect(frames[currentFrame]);
}

void AnimatedSprite::setFrameTime(const float frameTime) {
    this->frameTime = frameTime;
}

glm::vec2 AnimatedSprite::getSize() {
    return {frames[currentFrame].width, frames[currentFrame].height};
}

AnimatedSprite::Meta::Meta(AnimatedSprite *owner): IMeta(), _owner(owner),
                                                   _fieldGroup({}) {
    auto fields = std::vector<IField *>();
    auto *field = new FileField("Sprite", "The sprite file to use",
                                [this](const std::string &value) {
                                    this->_owner->path = value;
                                    this->_owner->setTexture(value);
                                },
                                [this]() { return this->_owner->path; });
    fields.push_back(field);
    this->_fieldGroup = InvisibleFieldGroup(fields);
}

std::string AnimatedSprite::Meta::getName() const {
    return "Animated Sprite";
}

std::string AnimatedSprite::Meta::getDescription() const {
    return "Animate a sprite on the screen";
}

bool AnimatedSprite::Meta::isUnique() const {
    return false;
}

bool AnimatedSprite::Meta::canBeRemoved() const {
    return true;
}

std::vector<const IComponent::IMeta::IFieldGroup *>
AnimatedSprite::Meta::getFieldGroups() const {
    return {&_fieldGroup};
}

void AnimatedSprite::deserialize(const json::IJsonObject *data) {
    if (data != nullptr && data->getType() == json::OBJECT) {
        const auto *const obj = dynamic_cast<const json::JsonObject *>(data);
        if (obj->contains("path")) {
            this->path = obj->getValue<json::JsonString>("path")->getValue();
            this->setTexture(this->path);
        }
        if (obj->contains("frames")) {
            auto frames = std::vector<sf::IntRect>();
            for (const auto *const frame: obj->getValue<json::JsonArray<
                     json::JsonObject> >("frames")->getValues()) {
                auto left = frame->getValue<json::JsonNumber>("left")->getFloatValue();
                auto top = frame->getValue<json::JsonNumber>("top")->getFloatValue();
                auto width = frame->getValue<json::JsonNumber>("width")->getFloatValue();
                auto height = frame->getValue<json::JsonNumber>("height")->
                        getFloatValue();
                frames.emplace_back(left, top, width, height);
            }
            this->setFrames(frames);
        }
        if (obj->contains("frameTime")) {
            this->frameTime = obj->getValue<json::JsonNumber>("frameTime")->
                    getFloatValue();
        }
        if (obj->contains("currentFrame")) {
            this->currentFrame = obj->getValue<json::JsonNumber>("currentFrame")->
                    getIntValue();
        }
    }
}

json::IJsonObject *AnimatedSprite::serializeData() {
    auto *obj = new json::JsonObject("data");
    obj->add(new json::JsonString("path", path));
    auto *frames = new json::JsonArray<json::JsonObject>("frames");
    for (const auto &frame: this->frames) {
        auto *frameObj = new json::JsonObject("");
        frameObj->add(new json::JsonNumber(frame.left, "left"));
        frameObj->add(new json::JsonNumber(frame.top, "top"));
        frameObj->add(new json::JsonNumber(frame.width, "width"));
        frameObj->add(new json::JsonNumber(frame.height, "height"));
        frames->add(frameObj);
    }
    obj->add(frames);
    obj->add(new json::JsonNumber(frameTime, "frameTime"));
    obj->add(new json::JsonNumber(static_cast<int>(currentFrame), "currentFrame"));
    return obj;
}

AnimatedSprite *AnimatedSprite::clone(IObject *owner) const {
    return new AnimatedSprite(owner, path, frames, frameTime, currentFrame);
}
