/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
*/

#ifndef STELLARFORGE_FIELDGROUP_HPP
#define STELLARFORGE_FIELDGROUP_HPP

#include "AFieldGroup.hpp"

/**
 * @class InvisibleFieldGroup
 * @brief A field group that is invisible in the UI.
 * @version v0.1.0
 * @since v0.1.0
 * @details This class inherits from AFieldGroup and is used to create a group of fields that are not visible in the user interface.
 */
class InvisibleFieldGroup final : public AFieldGroup {
public:
    /**
     * @brief Constructor for InvisibleFieldGroup.
     * @param fields A vector of pointers to IField objects representing the fields in this group.
     * @version v0.1.0
     * @since v0.1.0
     * @details Initializes the InvisibleFieldGroup with the given fields.
     */
    explicit InvisibleFieldGroup(
        const std::vector<IComponent::IMeta::IField *> &fields);
};

#endif //STELLARFORGE_FIELDGROUP_HPP
