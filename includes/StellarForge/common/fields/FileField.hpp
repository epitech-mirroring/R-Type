/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** FileField.hpp
*/

#ifndef FILEFIELD_HPP
#define FILEFIELD_HPP

#include <functional>

#include "AField.hpp"
#include "common/json/JsonString.hpp"

/**
 * @class FileField
 * @brief Represents a field that holds a file path.
 * @details This class inherits from AField and is used to store and manage a file path field.
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class FileField final : public AField {
protected:
 std::function<void(std::string)> _setCallback;
 std::function<std::string()> _getCallback;

public:
 /**
  * @brief Constructor for FileField.
  * @param name The name of the field.
  * @param description A brief description of the field.
  * @param setCallback The callback function to set the value of the field.
  * @param getCallback The callback function to get the value of the field.
  * @details Initializes the FileField with the given name and description.
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 FileField(std::string name, std::string description,
           std::function<void(std::string)> setCallback = nullptr,
           std::function<std::string()> getCallback = nullptr);


 void updateValue(std::any value) override;

 [[nodiscard]] std::any getValue() const override;

 [[nodiscard]] json::JsonString *serialize() const override;

 void deserialize(const json::IJsonObject *data) override;
};

#endif //FILEFIELD_HPP
