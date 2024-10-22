/*
** EPITECH PROJECT, 2024
** JSON
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonString.hpp"

#include <iostream>

using namespace json;

JsonString::JsonString(std::string value, std::string name)
    : _value(std::move(value)), _name(std::move(name)) {
}

std::string JsonString::stringify() const {
    return "\"" + this->_value + "\"";
}

void JsonString::parse(const IJsonParser & /*parser*/, const std::string &string) {
    this->_value = string.substr(1, string.size() - 2);
}

JsonType JsonString::getType() const {
    return STRING;
}

std::string JsonString::getName() const {
    return this->_name;
}

std::string JsonString::getValue() const {
    return this->_value;
}

void JsonString::setValue(const std::string &value) {
    this->_value = value;
}

JsonString::operator std::string() const {
    return this->_value;
}
