/*
** EPITECH PROJECT, 2024
** JSON
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/


#include "JsonBoolean.hpp"
using namespace json;

JsonBoolean::JsonBoolean(const bool value,
                         std::string name): IJsonPrimitiveObject(),
                                            _value(value),
                                            _name(std::move(name)) {
}

std::string JsonBoolean::stringify() const {
    return this->_value ? "true" : "false";
}

void JsonBoolean::parse(const IJsonParser & /*parser*/,
                        const std::string &string) {
    if (string == "true") {
        this->_value = true;
    } else if (string == "false") {
        this->_value = false;
    }
}

// @formatter:off
JsonType JsonBoolean::getType() const { // NOLINT(*-convert-member-functions-to-static)
    // @formatter:on
    return BOOLEAN;
}

std::string JsonBoolean::getName() const {
    return this->_name;
}

bool JsonBoolean::getValue() const {
    return this->_value;
}

void JsonBoolean::setValue(const bool &value) {
    this->_value = value;
}

JsonBoolean::operator bool() const {
    return this->_value;
}



