/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AFieldGroup.hpp
*/

#ifndef AFIELDGROUP_HPP
#define AFIELDGROUP_HPP
#include "common/IComponent.hpp"

/**
 * @class AFieldGroup
 * @brief This class is the abstract class for the FieldGroup class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AFieldGroup : virtual public IComponent::IMeta::IFieldGroup {
public:
 /**
  * @brief The constructor of the AFieldGroup class
  * @param name The name of the field group
  * @param description The description of the field group
  * @param fields The fields of the field group - vector of IComponent::IMeta::IField
  * @version v0.1.0
  * @since v0.1.0
  */
 AFieldGroup(std::string name, std::string description,
             const std::vector<IComponent::IMeta::IField *> &fields);

 /**
  * @brief The destructor of the AFieldGroup class
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 ~AFieldGroup() override = default;

 /**
  * @brief Get the name of the field group
  * @see IComponent::IMeta::IFieldGroup::getName
  * @return the name of the field group
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::string getName() const override;

 /**
  * @brief Get the description of the field group
  * @see IComponent::IMeta::IFieldGroup::getDescription
  * @return the description of the field group
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::string getDescription() const override;

 /**
  * @brief Get the fields of the field group
  * @see IComponent::IMeta::IFieldGroup::getFields
  * @return the fields of the field group
  * @version v0.1.0
  * @since v0.1.0
  * @see IComponent::IMeta::IField
  * @author Marius PAIN
  */
 [[nodiscard]] std::vector<IComponent::IMeta::IField *>
 getFields() const override;

protected:
 /**
  * @brief The name of the field group
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 std::string _name;

 /**
  * @brief The description of the field group
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 std::string _description;

 /**
  * @brief The fields of the field group
  * @note vector of IComponent::IMeta::IField
  * @version v0.1.0
  * @since v0.1.0
  * @see IComponent::IMeta::IField
  * @author Marius PAIN
  */
 std::vector<IComponent::IMeta::IField *> _fields;
};

#endif //AFIELDGROUP_HPP
