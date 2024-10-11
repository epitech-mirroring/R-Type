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

/**
 * @class BinaryVector
 * @brief A class for handling binary data in a vector.
 * @version v0.1.0
 * @since v0.1.0
 * @author landry Gigant
 */
class BinaryVector {
public:
    BinaryVector() = default;
    explicit BinaryVector(const std::vector<char> &vector);
    ~BinaryVector() = default;

    /**
     * @brief Pushes a string into the binary vector.
     * @param value The string to push.
     * @return Reference to the current BinaryVector object.
     */
    BinaryVector &pushString(const std::string& value);

    /**
     * @brief Pushes a value of any type into the binary vector.
     * @tparam T The type of the value.
     * @param value The value to push.
     * @return Reference to the current BinaryVector object.
     */
    template<class T>
    BinaryVector &push(T value)
    {
        char *ptr = reinterpret_cast<char *>(&value);

        for (int i = 0; i < sizeof(T); i++) {
            _vector.push_back(ptr[i]);
        }
        return *this;
    }

    /**
     * @brief Consumes a string from the binary vector.
     * @return The consumed string.
     */
    std::string consumeString();

    /**
     * @brief Consumes a value of any type from the binary vector.
     * @tparam T The type of the value.
     * @return The consumed value.
     */
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

    /**
     * @brief Assigns a vector of chars to the binary vector.
     * @param vector The vector of chars to assign.
     * @return Reference to the current BinaryVector object.
     */
    BinaryVector &operator=(const std::vector<char> &vector);

    /**
     * @brief Converts the binary vector to a vector of chars.
     * @return The vector of chars.
     */
    operator std::vector<char>() const;

private:
    std::vector<char> _vector;
};

/**
 * @namespace BinaryConversion
 * @brief A namespace for binary conversion utilities.
 * @version v0.1.0
 * @since v0.1.0
 * @author landry Gigant
 */
namespace BinaryConversion {

    /**
     * @brief Converts a string to a vector of chars.
     * @param value The string to convert.
     * @return The vector of chars.
     */
    std::vector<char> convertString(const std::string& value);

    /**
     * @brief Converts a value of any type to a vector of chars.
     * @tparam T The type of the value.
     * @param value The value to convert.
     * @return The vector of chars.
     */
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

    /**
     * @brief Consumes a string from a vector of chars.
     * @param _vector The vector of chars to consume from.
     * @return The consumed string.
     */
    std::string consumeString(std::vector<char> &_vector);

    /**
     * @brief Consumes a value of any type from a vector of chars.
     * @tparam T The type of the value.
     * @param _vector The vector of chars to consume from.
     * @return The consumed value.
     */
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

/**
 * @brief Concatenates two vectors of chars.
 * @param vec_a The first vector of chars.
 * @param vec_b The second vector of chars.
 * @return The concatenated vector of chars.
 */
std::vector<char> operator+(const std::vector<char> &&vec_a, const std::vector<char> &&vec_b);

/**
 * @brief Appends a vector of chars to another vector of chars.
 * @param vec_a The vector of chars to append to.
 * @param vec_b The vector of chars to append.
 * @return The appended vector of chars.
 */
std::vector<char> operator+=(std::vector<char> &vec_a, const std::vector<char> &&vec_b);

#endif //R_TYPE_REBORN_BINARYOPERATION_HPP
