/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** FileField.cpp
*/

#include "FileField.hpp"

FileField::FileField(std::string name, std::string description,
                     std::function<void(std::string)> setCallback,
                     std::function<std::string()> getCallback)
    : AField(std::move(name), std::move(description), IComponent::IMeta::STRING),
      _setCallback(std::move(setCallback)),
      _getCallback(std::move(getCallback)) {
}

void FileField::updateValue(const std::any value) {
    if (_setCallback) {
        _setCallback(std::any_cast<std::string>(value));
    }
}

std::any FileField::getValue() const {
    if (_getCallback) {
        return _getCallback();
    }
    return "";
}
