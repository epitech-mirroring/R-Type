/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
*/

#ifndef STELLARFORGE_VECTOR3FIELD_HPP
#define STELLARFORGE_VECTOR3FIELD_HPP

#include <utility>
#include "../AField.hpp"

/**
 * @class Vector3Field
 * @brief Represents a field that holds a 3D vector.
 * @version v0.1.0
 * @since v0.1.0
 * @details This class inherits from AField and is used to store and manage a 3D vector field.
 */
class Vector3Field : public AField {
public:
    /**
     * @brief Constructor for Vector3Field.
     * @param name The name of the field.
     * @param description A brief description of the field.
     * @version v0.1.0
     * @since v0.1.0
     * @details Initializes the Vector3Field with the given name and description.
     */
    Vector3Field(std::string name, std::string description);
};

#endif //STELLARFORGE_VECTOR3FIELD_HPP
