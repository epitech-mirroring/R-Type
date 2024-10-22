/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** UIText.cpp
**/

#include "UIText.hpp"

#include <utility>

#include "common/components/Transform.hpp"
#include "common/fields/StringField.hpp"
#include "common/json/JsonNumber.hpp"
#include "common/json/JsonString.hpp"
#include "graphics/GraphicsException.hpp"

UIText::UIText(IObject *owner, std::string textStr, const unsigned int size,
               const sf::Color color, const std::string &fontPath)
    : AComponent(owner, new Meta(this)), textString(std::move(textStr)),
      fontPath(fontPath),
      fontSize(size), color(color) {
    if (std::string(fontPath) == "default") {
        this->fontPath = findDefaultFontPath();
    }
    if (!font.loadFromFile(fontPath)) {
        throw GraphicsException(
            "Failed to load font from file: " + std::string(fontPath));
    }
    text.setFont(font);
    text.setString(textString);
    text.setCharacterSize(fontSize);
    text.setFillColor(color);
}

UIText::UIText(IObject *owner, const json::JsonObject *data): AComponent(
        owner, new Meta(this), data), fontPath(findDefaultFontPath()),
    fontSize(0), color(sf::Color::White) {
}

std::string UIText::findDefaultFontPath() {
#ifdef _WIN32
        return "C:\\Windows\\Fonts\\arial.ttf";
#elif defined(__linux__)
        return "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";
#else
    throw GraphicsException("Unknown OS: No default font available");
#endif
}

void UIText::render(sf::RenderWindow *window) {
    const auto *transformComponent = getParentComponent<Transform>();
    if (transformComponent != nullptr) {
        text.setPosition(transformComponent->getPosition().x,
                         transformComponent->getPosition().y);
        text.setRotation(transformComponent->getRotation().x);
        text.setScale(transformComponent->getScale().x,
                      transformComponent->getScale().y);
        window->draw(text);
    }
}

void UIText::setText(const std::string &textStr) {
    textString = textStr;
    text.setString(textString);
}

void UIText::setFont(const std::string &fontPath) {
    if (!font.loadFromFile(fontPath)) {
        throw GraphicsException(
            "Failed to load font from file: " + std::string(fontPath));
    }
    text.setFont(font);
    this->fontPath = fontPath;
}

void UIText::setSize(unsigned int size) {
    if (size <= 0) {
        throw GraphicsException("Font size must be greater than 0");
    }
    fontSize = size;
    text.setCharacterSize(fontSize);
}

void UIText::setColor(sf::Color color) {
    this->color = color;
    text.setFillColor(color);
}

glm::vec2 UIText::getSize() {
    return {text.getGlobalBounds().width, text.getGlobalBounds().height};
}

void UIText::runComponent() {
}

UIText::Meta::Meta(UIText *owner)
    : IMeta(), _owner(owner), _fieldGroup({}) {
    auto fields = std::vector<IField *>();
    auto *field = new StringField("Text", "The text to display",
                                  [this](const std::string &value) {
                                      this->_owner->setText(value);
                                  },
                                  [this]() { return this->_owner->textString; });
    _fieldGroup = InvisibleFieldGroup({field});
}

std::string UIText::Meta::getName() const {
    return "UIText";
}

std::string UIText::Meta::getDescription() const {
    return "The UIText component is used to render text on the screen.";
}

bool UIText::Meta::isUnique() const {
    return false;
}

bool UIText::Meta::canBeRemoved() const {
    return true;
}

std::vector<const IComponent::IMeta::IFieldGroup *>
UIText::Meta::getFieldGroups() const {
    return {&_fieldGroup};
}

json::IJsonObject *UIText::serializeData() {
    auto *const data = new json::JsonObject("data");
    data->add(new json::JsonString(textString, "text"));
    std::string fontName = fontPath;
    if (fontName.find_last_of('/') != std::string::npos) {
        fontName = fontName.substr(fontName.find_last_of('/') + 1);
    }
    if (fontName.find_last_of('.') != std::string::npos) {
        fontName = fontName.substr(0, fontName.find_last_of('.'));
    }
    data->add(new json::JsonString(fontName, "font"));
    data->add(new json::JsonNumber(static_cast<int>(fontSize), "size"));
    auto *const colorData = new json::JsonObject("color");
    colorData->add(new json::JsonNumber(color.r, "r"));
    colorData->add(new json::JsonNumber(color.g, "g"));
    colorData->add(new json::JsonNumber(color.b, "b"));
    colorData->add(new json::JsonNumber(color.a, "a"));
    data->add(colorData);
    return data;
}

void UIText::deserialize(const json::IJsonObject *data) {
    if (data == nullptr || data->getType() != json::OBJECT) {
        return;
    }
    const auto *const obj = dynamic_cast<const json::JsonObject *>(data);
    if (obj->contains("text")) {
        textString = obj->getValue<json::JsonString>("text")->getValue();
        text.setString(textString);
    }
    if (obj->contains("font")) {
        fontPath = obj->getValue<json::JsonString>("font")->getValue();
        if (!font.loadFromFile(fontPath)) {
            // TODO use font manager
            throw GraphicsException(
                "Failed to load font from file: " + std::string(fontPath));
        }
        text.setFont(font);
    }
    if (obj->contains("size")) {
        fontSize = obj->getValue<json::JsonNumber>("size")->getIntValue();
        text.setCharacterSize(fontSize);
    }
    if (obj->contains("color")) {
        const auto *const colorData = obj->getValue<json::JsonObject>("color");
        color.r = colorData->getValue<json::JsonNumber>("r")->getIntValue();
        color.g = colorData->getValue<json::JsonNumber>("g")->getIntValue();
        color.b = colorData->getValue<json::JsonNumber>("b")->getIntValue();
        color.a = colorData->getValue<json::JsonNumber>("a")->getIntValue();
        text.setFillColor(color);
    }
}

UIText *UIText::clone(IObject *owner) const {
    return new UIText(owner, textString, fontSize, color, fontPath);
}
