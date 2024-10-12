/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
*/

#ifndef INTRECTFIELDGROUP_HPP
#define INTRECTFIELDGROUP_HPP

#include <utility>
#include "../AField.hpp"

#include <utility>
#include "../AFieldGroup.hpp"

/**
 * @class IntRectFieldGroup
 * @brief A field group that holds a 2D integer rectangle.
 * @version v0.1.0
 * @since v0.1.0
 * @details This class inherits from AFieldGroup and is used to create a group of fields that hold a 2D integer rectangle.
 * @author Aubane NOURRY
 */
class IntRectFieldGroup : public AFieldGroup {
public:
    /**
     * @brief Constructor for IntRectFieldGroup.
     * @version v0.1.0
     * @since v0.1.0
     * @details Initializes the IntRectFieldGroup with the given fields.
     */
    explicit IntRectFieldGroup(std::string name, std::string description);
};

#endif //INTRECTFIELDGROUP_HPP
