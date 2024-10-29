/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonParser.hpp"

#include <any>
#include <iostream>

#include "JsonArray.hpp"
#include "JsonBoolean.hpp"
#include "JsonNull.hpp"
#include "JsonNumber.hpp"
#include "JsonObject.hpp"
#include "JsonString.hpp"

using namespace json;

std::function<IJsonObject *(const std::string &)> JsonParser::getParser(
    const std::string &obj, const std::string &key) const {
    if (obj[0] == '{') {
        return [this, key](
            const std::string &str) -> IJsonObject *{
            try {
                auto *json = new JsonObject(key);
                json->parse(*this, str);
                return json;
            } catch (const std::exception &e) {
                (void) e;
                return new JsonNull(key);;
            }
        };
    }
    if (obj[0] == '[') {
        return [this, key](const std::string &str) -> IJsonObject *{
            switch (str[1]) {
                case '"': {
                    auto *json = new JsonArray<JsonString>(key);
                    json->parse(*this, str);
                    return json;
                }
                case '{': {
                    auto *json = new JsonArray<JsonObject>(key);
                    json->parse(*this, str);
                    return json;
                }
                case 'f':
                case 't': {
                    auto *json = new JsonArray<JsonBoolean>(key);
                    json->parse(*this, str);
                    return json;
                }
                case '-':
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9': {
                    auto *json = new JsonArray<JsonNumber>(key);
                    json->parse(*this, str);
                    return json;
                }
                default:
                case 'n': {
                    auto *json = new JsonArray<JsonNull>(key);
                    json->parse(*this, str);
                    return json;
                }
            };
        };
    }
    if (obj[0] == '"') {
        return [this, key](const std::string &str) -> JsonString *{
            auto *json = new JsonString("", key);
            json->parse(*this, str);
            return json;
        };
    }
    if (obj[0] >= '0' && obj[0] <= '9' || obj[0] == '-') {
        return [this, key](const std::string &str) -> JsonNumber *{
            auto *json = new JsonNumber(key);
            json->parse(*this, str);
            return json;
        };
    }
    if (obj == "true" || obj == "false") {
        return [this, key](const std::string &str) -> JsonBoolean *{
            auto *json = new JsonBoolean(false, key);
            json->parse(*this, str);
            return json;
        };
    }

    return [*this, key](const std::string &/*str*/) -> JsonNull *{
        return new JsonNull(key);
    };
}

std::size_t
JsonParser::findContextEnd(const std::string &string, const std::size_t start,
                           const bool skipToColon) const {
    int nb_braces = 0;
    bool in_string = false;
    std::size_t const len = string.length();
    std::size_t current = start;

    if (skipToColon) {
        while (string[current] != ':' && current < len) {
            current++;
        }
    }
    while (current < len && (nb_braces > 0 || string[current] != ',' || in_string)) {
        if (string[current] == '"') {
            in_string = !in_string;
        }
        if (string[current] == '{' || string[current] == '[') {
            nb_braces++;
        }
        if (string[current] == '}' || string[current] == ']') {
            nb_braces--;
        }
        current++;
    }
    return current;
}

std::size_t JsonParser::findContextStart(const std::string &string,
                                         const std::size_t start) const {
    std::size_t current = start;

    while (current < string.length() && string[current] != ':') {
        current++;
    }
    while (current < string.length() && string[current] != '{' && string[current] != '['
           && string[current] != '"' && string[current] != 't' && string[current] != 'f'
           && string[current] != 'n' && (
               string[current] < '0' || string[current] > '9') && string[current] !=
           '-') {
        current++;
    }
    return current;
}

std::string JsonParser::cleanString(const std::string &string) const {
    // Remove spaces, tabs, and newlines if not in a string
    std::string cleanedString;
    bool inString = false;
    for (const auto &_char: string) {
        if (_char == '"') {
            inString = !inString;
        }
        if (inString || (_char != ' ' && _char != '\t' && _char != '\n')) {
            cleanedString += _char;
        }
    }
    return cleanedString;
}

std::string JsonParser::findKey(const std::string &string,
                                const std::size_t start) const {
    const std::size_t len = string.length();
    std::size_t current = start;
    while (current < len && string[current] != '"') {
        current++;
    }
    if (current == len) {
        return "";
    }
    return string.substr(start, current - start);
}

IJsonObject *JsonParser::parse(const std::string &string) const {
    const std::string cleanedString = cleanString(string);
    std::string key;
    if (cleanedString[0] != '{' && cleanedString[0] != '[') {
        key = findKey(cleanedString, 0);
    }
    const std::function<IJsonObject *(const std::string &)> parser = getParser(
        cleanedString, key);
    return parser(cleanedString);
}
