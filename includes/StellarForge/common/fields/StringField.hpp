/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
*/

#ifndef STELLARFORGE_STRINGFIELD_HPP
#define STELLARFORGE_STRINGFIELD_HPP
#include <functional>

#include "AField.hpp"
#include "common/json/JsonString.hpp"

/**
 * @class StringField
 * @brief Represents a field that holds a string.
 * @version v0.1.0
 * @since v0.1.0
 * @details This class inherits from AField and is used to store and manage a 3D vector field.
 */
class StringField final : public AField {
protected:
    std::function<void(std::string)> _setCallback;
    std::function<std::string()> _getCallback;

public:
    /**
     * @brief Constructor for StringField.
     * @param name The name of the field.
     * @param description A brief description of the field.
     * @param setCallback The callback function to set the value of the field.
     * @param getCallback The callback function to get the value of the field.
     * @version v0.1.0
     * @since v0.1.0
     * @details Initializes the StringField with the given name and description.
     */
    StringField(std::string name, std::string description,
                const std::function<void(std::string)> &setCallback = nullptr,
                const std::function<std::string()> &getCallback = nullptr);

    void updateValue(std::any value) override;

    [[nodiscard]] std::any getValue() const override;

    [[nodiscard]] json::JsonString *serialize() const override;

    void deserialize(const json::IJsonObject *data) override;
};

#endif //STELLARFORGE_STRINGFIELD_HPP
