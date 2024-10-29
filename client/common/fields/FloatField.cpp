/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "FloatField.hpp"

FloatField::FloatField(const std::string &name, const std::string &description,
                       const std::function<void(float)> &setCallback,
                       const std::function<float()> &
                       getCallback): AField(name, description, IComponent::IMeta::FLOAT),
                                     _setCallback(setCallback),
                                     _getCallback(getCallback) {
}

void FloatField::updateValue(const std::any value) {
    _setCallback(std::any_cast<float>(value));
}

std::any FloatField::getValue() const {
    return _getCallback();
}
