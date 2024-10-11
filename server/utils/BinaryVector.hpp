/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
*/

#ifndef R_TYPE_REBORN_BINARYOPERATION_HPP
#define R_TYPE_REBORN_BINARYOPERATION_HPP

#include <vector>
#include <string>

class BinaryVector {
public:
    BinaryVector() = default;
    explicit BinaryVector(const std::vector<char> &vector);
    ~BinaryVector() = default;

    BinaryVector &pushString(const std::string& value);

    template<class T>
    BinaryVector &push(T value)
    {
        char *ptr = reinterpret_cast<char *>(&value);

        for (int i = 0; i < sizeof(T); i++) {
            _vector.push_back(ptr[i]);
        }
        return *this;
    }

    std::string consumeString();

    template<class T>
    T consume()
    {
        T value;
        char *ptr = reinterpret_cast<char *>(&value);

        for (int i = 0; i < sizeof(T); i++) {
            ptr[i] = _vector[i];
        }
        _vector.erase(_vector.begin(), _vector.begin() + sizeof(T));
        return value;
    }

    BinaryVector &operator=(const std::vector<char> &vector);

    operator std::vector<char>() const;

private:
    std::vector<char> _vector;
};

namespace BinaryConversion {

    std::vector<char> convertString(const std::string& value);

    template<class T>
    std::vector<char> convert(T value)
    {
        std::vector<char> _vector;
        char *ptr = reinterpret_cast<char *>(&value);

        for (int i = 0; i < sizeof(T); i++) {
            _vector.push_back(ptr[i]);
        }
        return _vector;
    }

    std::string consumeString(std::vector<char> &_vector);

    template<class T>
    T consume(std::vector<char> &_vector)
    {
        T value;
        char *ptr = reinterpret_cast<char *>(&value);

        for (int i = 0; i < sizeof(T); i++) {
            ptr[i] = _vector[i];
        }
        _vector.erase(_vector.begin(), _vector.begin() + sizeof(T));
        return value;
    }
}

std::vector<char> operator+(const std::vector<char> &&vec_a, const std::vector<char> &&vec_b);
std::vector<char> operator+=(std::vector<char> &vec_a, const std::vector<char> &&vec_b);


#endif //R_TYPE_REBORN_BINARYOPERATION_HPP
