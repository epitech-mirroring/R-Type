/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP

#include "IComponent.hpp"

/**
 * @class AComponent
 * @brief This class is the abstract class for the Component class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AComponent : virtual public IComponent
{
public:
 /**
  * @brief The destructor of the AComponent class
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 ~AComponent() override = default;

 /**
  * @brief The start function of the component
  * * This is meant to be runt by the parent object and initialize the component
  * @note This is not a pure virtual function and can be overriden in the child class
  * @see IComponent::onStart
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
  void onStart() override;

 /**
  * @brief The before function of the component
  * This is meant to be runt by the parent object and update the component before the rendering
  * @note This is not a pure virtual function and can be overriden in the child class
  * @see IComponent::beforeRendering
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 void beforeRendering() override;

 /**
  * @brief The update function of the component.
  * This is meant to be runt by the parent object and update the component every frame
  * @note This is a pure virtual function and must be implemented in the child class
  * @see IComponent::runComponent
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 void runComponent() override = 0;

 /**
  * @brief The after function of the component
  * This is meant to be runt by the parent object and update the component after the rendering
  * @note This is not a pure virtual function and can be overriden in the child class
  * @see IComponent::afterRendering
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 void afterRendering() override;

 /**
  * @brief This function is used to check if the component is active
  * @see IComponent::isActive
  * @return True if the component is active, false otherwise
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 bool isActive() override;

 /**
  * @brief This function is used to set the state of the component
  * @param state The state of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setActive(bool state);

 /**
  * @brief Returns a non-owning and non-null pointer to the owner of the component
  * @see IComponent::getOwner
  * @return the owner of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] IObject* getOwner() override;

 /**
  * @brief Get the meta of the component
  * @see IComponent::getMeta
  * @return the meta of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] const IMeta& getMeta() const override;

protected:
 /**
  * @brief The constructor of the AComponent class
  * @param owner The owner of the component
  * @param meta The meta of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 AComponent(IObject* owner, const IMeta& meta);

 /**
  * @brief The owner of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
 */
 IObject* _owner;

 /**
  * @brief The meta of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 const IMeta& _meta;

 bool _isActive; //< The state of the component
};

#endif //ACOMPONENT_HPP
