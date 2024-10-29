/*
** EPITECH PROJECT, 2024
** JSON
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonArray.hpp"
#include "IJsonParser.hpp"
#include <fstream>

#include "JsonBoolean.hpp"
#include "JsonNull.hpp"
#include "JsonNumber.hpp"
#include "JsonObject.hpp"
#include "JsonString.hpp"

using namespace json;

template<typename T>
JsonArray<T>::JsonArray(std::string name): _name(std::move(name)) {
    static_assert(std::is_base_of_v<IJsonObject, T>,
                  "T must inherit from IJsonObject");
}

template<typename T>
JsonArray<T>::~JsonArray() {
    for (auto *obj: this->_values) {
        delete obj;
    }
}

template<typename T>
std::string JsonArray<T>::stringify() const {
    std::string str = "[";
    for (auto &elem: this->_values) {
        str += elem->stringify();
        if (&elem != &this->_values.back()) {
            str += ",";
        }
    }
    str += "]";
    return str;
}


template<typename T>
void JsonArray<T>::parse(const IJsonParser &parser, const std::string &string) {
    std::string const cleaned = parser.cleanString(string);
    std::size_t const len = cleaned.length();
    std::size_t start = 1;

    this->_values.clear();
    while (start < len) {
        std::size_t end = parser.findContextEnd(cleaned, start, false);
        if (end == len) {
            end--;
        }
        std::string const obj = cleaned.substr(start, end - start);
        if (obj.empty()) {
            break;
        }
        _values.push_back(
            dynamic_cast<T *>(parser.getParser(
                obj, std::to_string(_values.size()))(obj)));
        start = end + 1;
    }
}

template<typename T>
std::string JsonArray<T>::getName() const {
    return this->_name;
}

template<typename T>
JsonType JsonArray<T>::getType() const {
    return ARRAY;
}

template<typename T>
std::size_t JsonArray<T>::size() const {
    return this->_values.size();
}

template<typename T>
void JsonArray<T>::add(T *value) {
    this->_values.push_back(value);
}

template<typename T>
void JsonArray<T>::remove(std::size_t index) {
    if (index >= this->_values.size()) {
        return;
    }
    delete this->_values[index];
    this->_values.erase(this->_values.begin() + index);
}

template<typename T>
std::vector<T *> JsonArray<T>::getValues() const {
    return this->_values;
}

template<typename T>
[[nodiscard]]
T *JsonArray<T>::getValue(const std::size_t &index) const {
    if (index >= this->_values.size()) {
        return nullptr;
    }
    return dynamic_cast<T *>(this->_values[index]);
}

template<typename T>
JsonArray<T>::operator std::vector<T *>() const {
    return this->_values;
}

template<typename T>
T *JsonArray<T>::operator[](const std::size_t &index) const {
    return this->getValue(index);
}

template<typename T>
T *JsonArray<T>::at(const std::size_t &index) const {
    return this->getValue(index);
}

template class json::JsonArray<json::JsonNumber>;
template class json::JsonArray<json::JsonObject>;
template class json::JsonArray<json::JsonString>;
template class json::JsonArray<json::JsonBoolean>;
template class json::JsonArray<json::JsonNull>;
