/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** CPPMonoBehaviour.cpp
*/

#include "CPPMonoBehaviour.hpp"

#include "common/fields/FileField.hpp"

CPPMonoBehaviour::CPPMonoBehaviour(IObject *owner): AComponent(owner, new Meta(this)) {
}


void CPPMonoBehaviour::beforeRendering() {
    before();
}

void CPPMonoBehaviour::runComponent() {
    update();
}

void CPPMonoBehaviour::afterRendering() {
    after();
}

void CPPMonoBehaviour::before() {
}

void CPPMonoBehaviour::after() {
}

CPPMonoBehaviour::Meta::Meta(CPPMonoBehaviour *owner): _owner(owner), _fieldGroup({}) {
    auto fields = std::vector<IField *>();
    auto *field = new FileField("Script", "The script file to use",
                                [this](const std::string &value) {
                                    this->_owner->file_path = value;
                                },
                                [this]() { return this->_owner->file_path; });
    fields.push_back(field);
    this->_fieldGroup = InvisibleFieldGroup(fields);
}

std::string CPPMonoBehaviour::Meta::getName() const {
    return "C++ MonoBehaviour";
}


std::string CPPMonoBehaviour::Meta::getDescription() const {
    return "Script component written in C++";
}

bool CPPMonoBehaviour::Meta::isUnique() const {
    return false;
}

bool CPPMonoBehaviour::Meta::canBeRemoved() const {
    return true;
}

std::vector<const IComponent::IMeta::IFieldGroup *>
CPPMonoBehaviour::Meta::getFieldGroups() const {
    return {&_fieldGroup};
}

void CPPMonoBehaviour::onCreation() {
    start();
}

void CPPMonoBehaviour::onDeletion() {
    end();
}
