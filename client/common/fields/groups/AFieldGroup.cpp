/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AFieldGroup.cpp
*/

#include "AFieldGroup.hpp"

#include <utility>

AFieldGroup::AFieldGroup(std::string name, std::string description,
                         const std::vector<IComponent::IMeta::IField *> &
                         fields): _name(std::move(name)),
                                  _description(std::move(description)), _fields(fields) {
}

std::string AFieldGroup::getName() const {
    return this->_name;
}

std::string AFieldGroup::getDescription() const {
    return this->_description;
}

std::vector<IComponent::IMeta::IField *> AFieldGroup::getFields() const {
    return this->_fields;
}
