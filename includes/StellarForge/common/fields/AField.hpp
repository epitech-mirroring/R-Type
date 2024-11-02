/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AField.hpp
*/

#ifndef AFIELD_HPP
#define AFIELD_HPP
#include "common/IComponent.hpp"

/**
 * @class AField
 * @brief This class is the abstract class for the Field class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AField : virtual public IComponent::IMeta::IField {
public:
 /**
  * @brief The constructor of the AField class
  * @param name The name of the field
  * @param description The description of the field
  * @param type The type of the field (FieldType)
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 AField(std::string name, std::string description, IComponent::IMeta::FieldType type);

 /**
  * @brief The destructor of the AField class
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 ~AField() override = default;

 /**
  * @brief Get the name of the field
  * @see IComponent::IMeta::IField::getName
  * @return the name of the field
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::string getName() const override;

 /**
  * @brief Get the description of the field
  * @see IComponent::IMeta::IField::getDescription
  * @return the description of the field
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::string getDescription() const override;

 /**
  * @brief Get the type of the field
  * @see IComponent::IMeta::IField::getType
  * @return the type of the field
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] IComponent::IMeta::FieldType getType() const override;

protected:
 /**
  * @brief The name of the field
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 std::string _name;

 /**
  * @brief The description of the field
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 std::string _description;

 /**
  * @brief The type of the field
  * @see IComponent::IMeta::IField::FieldType
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 IComponent::IMeta::FieldType _type;
};

#endif //AFIELD_HPP
