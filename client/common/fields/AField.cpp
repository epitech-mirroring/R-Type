/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AField.cpp
*/

#include "AField.hpp"

#include <utility>

AField::AField(std::string name, std::string description,
               const IComponent::IMeta::FieldType type): _type(type),
                                                         _description(
                                                             std::move(description)),
                                                         _name(std::move(name)) {
}

std::string AField::getName() const {
    return this->_name;
}

std::string AField::getDescription() const {
    return this->_description;
}

IComponent::IMeta::FieldType AField::getType() const {
    return this->_type;
}
