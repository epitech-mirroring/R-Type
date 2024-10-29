/*
** EPITECH PROJECT, 2024
** JSON
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonNumber.hpp"

#include <iostream>
using namespace json;

JsonNumber::JsonNumber(std::string name): IJsonPrimitiveObject(),
                                          _name(std::move(name)),
                                          _value({0}),
                                          _isFloat(UNCERTAIN) {
}

JsonNumber::JsonNumber(const int value, std::string name): IJsonPrimitiveObject(),
                                                           _name(std::move(name)),
                                                           _value({value}),
                                                           _isFloat(FALSE) {
}

JsonNumber::JsonNumber(const float value, std::string name): IJsonPrimitiveObject(),
    _name(std::move(name)),
    _isFloat(TRUE),
    _value({}) {
    this->_value.f = value;
}

std::string JsonNumber::stringify() const {
    if (this->_isFloat == TRUE) {
        return std::to_string(this->_value.f);
    }
    if (this->_isFloat == FALSE) {
        return std::to_string(this->_value.i);
    }
    return "";
}

void JsonNumber::parse(const IJsonParser & /*parser*/, const std::string &string) {
    if (string.find('.') != std::string::npos) {
        this->_value.f = std::stof(string);
        this->_isFloat = TRUE;
    } else {
        this->_value.i = std::stoi(string);
        this->_isFloat = FALSE;
    }
}

// @formatter:off
JsonType JsonNumber::getType() const { // NOLINT(*-convert-member-functions-to-static)
    // @formatter:on
    return NUMBER;
}

std::string JsonNumber::getName() const {
    return this->_name;
}

int JsonNumber::getIntValue() const {
    return this->_value.i;
}

float JsonNumber::getFloatValue() const {
    return this->_value.f;
}

bool JsonNumber::isFloat() const {
    return this->_isFloat == TRUE;
}

JsonNumberValue JsonNumber::getValue() const {
    return this->_value;
}

void JsonNumber::setValue(const int value) {
    this->_value.i = value;
    this->_isFloat = FALSE;
}

void JsonNumber::setValue(const float value) {
    this->_value.f = value;
    this->_isFloat = TRUE;
}

JsonNumber::operator int() const {
    if (this->_isFloat == TRUE) {
        return static_cast<int>(this->_value.f);
    }
    return this->_value.i;
}

JsonNumber::operator float() const {
    if (this->_isFloat == FALSE) {
        return static_cast<float>(this->_value.i);
    }
    return this->_value.f;
}

void JsonNumber::setValue(const JsonNumberValue &value) {
    this->_value = value;
}

JsonNumber::operator JsonNumberValue() const {
    return this->_value;
}
