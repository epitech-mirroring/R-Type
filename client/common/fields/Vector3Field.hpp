/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
*/

#ifndef STELLARFORGE_VECTOR3FIELD_HPP
#define STELLARFORGE_VECTOR3FIELD_HPP
#include <functional>
#include <glm/vec3.hpp>

#include "AField.hpp"

/**
 * @class Vector3Field
 * @brief Represents a field that holds a 3D vector.
 * @version v0.1.0
 * @since v0.1.0
 * @details This class inherits from AField and is used to store and manage a 3D vector field.
 */
class Vector3Field final : public AField {
protected:
    std::function<void(glm::vec3)> _setCallback;
    std::function<glm::vec3()> _getCallback;

public:
    /**
     * @brief Constructor for Vector3Field.
     * @param name The name of the field.
     * @param description A brief description of the field.
     * @param setCallback The callback function to set the value of the field.
     * @param getCallback The callback function to get the value of the field.
     * @version v0.1.0
     * @since v0.1.0
     * @details Initializes the Vector3Field with the given name and description.
     */
    Vector3Field(std::string name, std::string description,
                 const std::function<void(glm::vec3)> &setCallback = nullptr,
                 const std::function<glm::vec3()> &getCallback = nullptr);

    void updateValue(std::any value) override;

    [[nodiscard]] std::any getValue() const override;
};

#endif //STELLARFORGE_VECTOR3FIELD_HPP
