/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP
#include "common/IComponent.hpp"
#include "common/IObject.hpp"
#include "common/json/JsonObject.hpp"

/**
 * @class AComponent
 * @brief This class is the abstract class for the Component class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AComponent : virtual public IComponent {
public:
 /**
  * @brief The destructor of the AComponent class
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 ~AComponent() override;

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
 [[nodiscard]] IObject *getOwner() override;

 /**
  * @brief Get the meta of the component
  * @see IComponent::getMeta
  * @return the meta of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 [[nodiscard]] const IMeta &getMeta() const override;

 template<typename T>
T *getParentComponent() {
  static_assert(std::is_base_of_v<IComponent, T>, "T must inherit from IComponent");
  for (auto &component: this->_owner->getComponents()) {
   if (dynamic_cast<T *>(component) != nullptr) {
    return dynamic_cast<T *>(component);
   }
  }
  return nullptr;
 }

 [[nodiscard]] json::IJsonObject *serialize() final;

 virtual void deserialize(const json::IJsonObject *data) = 0;

 /**
 * @brief The creation function of the component
 * * This is meant to be runt by the parent object and initialize the component
 * @note This is not a pure virtual function and can be overriden in the child class
 * @see IComponent::onCreation
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
 void onCreation() override;

 /**
 * @brief The deletion function of the component
 * * This is meant to be runt by the parent object and delete the component
 * @note This is not a pure virtual function and can be overriden in the child class
 * @see IComponent::onDeletion
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
 void onDeletion() override;

protected:
 /**
  * @brief The constructor of the AComponent class
  * @param owner The owner of the component
  * @param meta The meta of the component
  * @param data The data of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 AComponent(IObject *owner, const IMeta *meta, const json::JsonObject *data = nullptr);

 /**
  * @brief The owner of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
 */
 IObject *_owner;

 /**
  * @brief The meta of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 const IMeta *_meta;

 bool _isActive; //< The state of the component

 [[nodiscard]] virtual json::IJsonObject *serializeData() = 0;
};

#endif //ACOMPONENT_HPP
