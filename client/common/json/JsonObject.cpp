/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/


#include "JsonObject.hpp"
#include "IJsonParser.hpp"
#include <fstream>
#include <iostream>
using namespace json;

JsonType JsonObject::getType() const {
    return OBJECT;
}

JsonObject::~JsonObject() {
    for (auto &[name, object_ptr]: this->_objects) {
        delete object_ptr;
    }
}

JsonObject::JsonObject(std::string name): _name(std::move(name)) {
}

void JsonObject::remove(const std::string &name) {
    if (this->_objects.find(name) == this->_objects.end()) {
        return;
    }
    if (this->_objects[name] != nullptr) {
        delete this->_objects[name];
    }
    this->_objects.erase(name);
}

std::string JsonObject::getName() const {
    return this->_name;
}

void JsonObject::add(IJsonObject *value) {
    if (value == nullptr) {
        return;
    }
    if (this->_objects.find(value->getName()) != this->_objects.end()) {
        delete this->_objects[value->getName()];
    }
    this->_objects[value->getName()] = value;
}

std::string JsonObject::stringify() const {
    std::string str = "{";
    for (const auto &[name, object]: this->_objects) {
        str += "\"" + name + "\":" + object->stringify() + ",";
    }
    if (str.back() == ',') {
        str.pop_back();
    }
    str += "}";
    return str;
}

void JsonObject::parse(const IJsonParser &parser, const std::string &string) {
    const std::string cleaned = parser.cleanString(string);
    std::size_t const len = cleaned.length();

    for (std::size_t i = 0; i < len; i++) {
        if (cleaned[i] != '"') {
            continue;
        }
        std::string const key = parser.findKey(cleaned, i + 1);
        const std::size_t start = parser.findContextStart(cleaned, i);
        std::size_t end = parser.findContextEnd(cleaned, i + 1);
        if (end == len) {
            end--;
        }
        std::string const obj = cleaned.substr(start, end - start);
        this->add(parser.getParser(obj, key)(obj));
        i = end;
    }
}

void JsonObject::setValue(const std::string &key, IJsonObject *value) {
    if (this->_objects.find(key) != this->_objects.end()) {
        delete this->_objects[key];
    }
    this->_objects[key] = value;
}

bool JsonObject::contains(const std::string &key) const {
    return this->_objects.find(key) != this->_objects.end();
}
