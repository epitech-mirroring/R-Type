/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
*/

#include "BinaryVector.hpp"

std::vector<char> BinaryConversion::convertString(const std::string& value)
{
    std::vector<char> _vector;

    for (char const chr : value) {
        _vector.push_back(chr);
    }
    _vector.push_back('\0');
    return _vector;
}

std::string BinaryConversion::consumeString(std::vector<char> &_vector)
{
    std::string value;

    while (_vector[0] != '\0') {
        value += _vector[0];
        _vector.erase(_vector.begin());
    }
    _vector.erase(_vector.begin());
    return value;
}

std::vector<char> operator+(const std::vector<char> &&vec_a, const std::vector<char> &&vec_b)
{
    std::vector<char> vec_c = vec_a;

    vec_c.insert(vec_c.end(), vec_b.begin(), vec_b.end());
    return vec_c;
}

std::vector<char> operator+=(std::vector<char> &vec_a, const std::vector<char> &&vec_b)
{
    vec_a.insert(vec_a.end(), vec_b.begin(), vec_b.end());
    return vec_a;
}
