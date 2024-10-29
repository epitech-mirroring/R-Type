/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
*/

#include "Vector3Field.hpp"

Vector3Field::Vector3Field(std::string name, std::string description,
                           const std::function<void(glm::vec3)> &setCallback,
                           const std::function<glm::vec3()> &getCallback)
    : AField(std::move(name), std::move(description),
             IComponent::IMeta::VECTOR3), _setCallback(setCallback),
      _getCallback(getCallback) {
}

void Vector3Field::updateValue(const std::any value) {
    if (_setCallback) {
        _setCallback(std::any_cast<glm::vec3>(value));
    }
}

std::any Vector3Field::getValue() const {
    if (_getCallback) {
        return _getCallback();
    }
    return glm::vec3(0, 0, 0);
}
