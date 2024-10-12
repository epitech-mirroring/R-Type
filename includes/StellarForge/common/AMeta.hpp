/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** AMeta
*/

#ifndef AMETA_HPP
#define AMETA_HPP

#include "IComponent.hpp"

/**
 * @class AMeta
 * @brief This class is the abstract class for the Meta class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AMeta : virtual public IComponent::IMeta
{
public:
 /**
  * @brief The constructor of the AMeta class
  * @param name The name of the meta
  * @param description The description of the meta
  * @param isUnique If the meta is unique
  * @param isRemovable If the meta can be removed
  * @param fieldGroups The field groups of the meta
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 AMeta(std::string name, std::string description, bool isUnique, bool isRemovable,
       std::vector<IFieldGroup*>&& fieldGroups);

 /**
  * @brief The destructor of the AMeta class
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 ~AMeta() override = default;

 /**
  * @brief Get the name of the meta
  * @see IComponent::IMeta::getName
  * @return the name of the meta
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::string getName() const override;

 /**
 * @brief Get the description of the meta
 * @see IComponent::IMeta::getDescription
 * @return the description of the meta
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
 [[nodiscard]] std::string getDescription() const override;

 /**
  * @brief Check if the meta is unique
  * @see IComponent::IMeta::isUnique
  * @return true if the meta is unique, false otherwise
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] bool isUnique() const override;

 /**
  * @brief Check if the meta can be removed
  * @see IComponent::IMeta::canBeRemoved
  * @return true if the meta can be removed, false otherwise
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] bool canBeRemoved() const override;

 /**
  * @brief Get the field groups of the meta
  * @see IComponent::IMeta::getFieldGroups
  * @return the field groups of the meta
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] std::vector<IFieldGroup*> getFieldGroups() const override;

protected:
 /**
  * @brief The name of the meta
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 std::string _name;

 /**
  * @brief The description of the meta
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 std::string _description;

 /**
  * @brief The field groups of the meta
  * @version v0.1.0
  * @since v0.1.0
  * @see IComponent::IMeta::IFieldGroup
  * @author Marius PAIN
  */
 std::vector<IFieldGroup*> _fieldGroups;

 /**
  * @brief If the meta is unique
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 bool _isUnique;

 /**
  * @brief If the meta can be removed
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 bool _isRemovable;
};

#endif //AMETA_HPP
