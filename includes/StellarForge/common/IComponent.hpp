/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP
#include <any>
#include <cstdint>
#include <string>
#include <vector>

#include "json/IJsonObject.hpp"
#include "json/JsonObject.hpp"

// Forward declaration of IObject
class IObject;

/**
 * @class IComponent
 * @brief The interface for the components
 * @version v0.1.0
 * @since v0.1.0
 * @author Axel ECKENBERG
 */
class IComponent {
public:
 /**
  * @brief The destructor of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual ~IComponent() = default;

 /**
  * @brief The creation function of the component
  * This is meant to be runt by the parent object and initialize the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 virtual void onCreation() = 0;

 /**
  * @brief The deletion function of the component
  * This is meant to be runt by the parent object and deletion the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 virtual void onDeletion() = 0;

 /**
  * @brief The start function of the component
  * This is meant to be runt before the rendering of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 virtual void beforeRendering() = 0;

 /**
  * @brief The update function of the component.
  * This is meant to be runt by the parent object and update the component every frame
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void runComponent() = 0;

 /**
  * @brief The after function of the component
  * This is meant to be runt by the parent object and update the component after the rendering
  * @version v0.1.0
  * @since v0.1.0
  * @author Marius PAIN
  */
 virtual void afterRendering() = 0;

 /**
  * @brief Returns a non-owning and non-null pointer to the owner of the component
  * @return the owner of the component
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual IObject *getOwner() = 0;

 /**
  * @brief This function is used to check if the component is active
  * @return True if the component is active, false otherwise
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 virtual bool isActive() = 0;

 /**
  * @class IComponent::IMeta
  * @brief The interface for components meta
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 class IMeta {
 public:
  /**
   * @brief The destructor of the component's meta
   */
  virtual ~IMeta() = default;

  /**
   * @brief Returns the name of the component
   * This is used to identify the component but also in the editor
   * display
   * @return the name of the component
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  [[nodiscard]]
  virtual std::string getName() const = 0;

  /**
   * @brief The description of the component
   * This is used to give more information about the component
   * @return the description of the component
   */
  [[nodiscard]]
  virtual std::string getDescription() const = 0;

  /**
   * @brief Returns whether the component is unique or not
   * It defines if the user can add multiple components of the same
   * type to the same entity
   * @return true if the component is unique, false otherwise
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  [[nodiscard]]
  virtual bool isUnique() const = 0;

  /**
   * @brief Returns whether the component can be removed or not
   * It defines if the user can remove the component from the entity
   * @return true if the component can be removed, false otherwise
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  [[nodiscard]]
  virtual bool canBeRemoved() const = 0;


  /**
   * @enum IComponent::IMeta::FieldType
   * @brief All types a field can have
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  enum FieldType: uint8_t {
   STRING,
   INT,
   FLOAT,
   BOOL,
   ENUM,
   VECTOR2,
   VECTOR3,
   VECTOR4,
   COLOR,
   TEXTURE,
   SOUND,
   MUSIC,
   ENTITY,
   COMPONENT
  };


  /**
   * @class IComponent::IMeta::IField
   * @brief The interface for the component's fields meta
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  class IField {
  public:
   /**
    * @brief The destructor of the field
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   virtual ~IField() = default;

   /**
    * @brief Returns the name of the field
    * This is used to identify the field but also in the editor
    * display
    * @return the name of the field
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual std::string getName() const = 0;

   /**
    * @brief Returns the description of the field
    * This is used to give more information about the field
    * @return the description of the field
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual std::string getDescription() const = 0;

   /**
    * @brief The type of the field
    * This is used to define the type of the field
    * @return the type of the field
    * @see IComponent::IMeta::IField::FieldType
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual FieldType getType() const = 0;

   /**
    * @brief Ran when the field is updated
    * @details This function is run when the field is updated,
    * whether it is from the editor or from the file
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   virtual void updateValue(std::any value) = 0;

   /**
    * @brief Returns the value of the field
    * @return the value of the field
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual std::any getValue() const = 0;
  };

  /**
   * @class IComponent::IMeta::IFieldGroup
   * @brief The interface for the component's field groups meta.
   * This class is intended to describe a group of fields in the editor
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  class IFieldGroup {
  public:
   /**
    * @brief The destructor of the field group
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   virtual ~IFieldGroup() = default;

   /**
    * @brief Returns the name of the field group
    * This is used to identify the field group but also in the editor
    * display
    * @return the name of the field group
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual std::string getName() const = 0;

   /**
    * @brief Returns the description of the field group
    * This is used to give more information about the field group
    * @return the description of the field group
    * @version v0.1.0
    * @since v0.1.0
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual std::string getDescription() const = 0;

   /**
    * @brief Returns the fields of the field group
    * @return the fields of the field group
    * @version v0.1.0
    * @since v0.1.0
    * @see IComponent::IMeta::IField
    * @author Axel ECKENBERG
    */
   [[nodiscard]]
   virtual std::vector<IField *> getFields() const = 0;
  };

  /**
   * @brief Returns field groups of the component
   * @return the field groups of the component
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  [[nodiscard]]
  virtual std::vector<const IFieldGroup *> getFieldGroups() const = 0;
 };

 /**
  * @brief Gives the meta of the component
  * This is used to define the meta of the component
  * @return the meta of the component
  * @version v0.1.0
  * @since v0.1.0
  * @see IComponent::IMeta
  * @author Axel ECKENBERG
  */
 [[nodiscard]] virtual const IMeta &getMeta() const = 0;

 /**
  * @brief Serialize the component
  * This is used to serialize the component to a JSON object
  * @return the serialized component
  * @version v0.1.0
  * @since v0.1.0
  * @see json::IJsonObject
  */
 [[nodiscard]] virtual json::IJsonObject *serialize() = 0;

 [[nodiscard]] virtual IComponent *clone(IObject *owner) const = 0;
};

template<typename T>
struct IsValidComponent {
 static constexpr bool value = std::is_constructible_v<T, IObject *, const
                                json::JsonObject *>
                               &&
                               std::is_base_of_v<IComponent, T>;
};

#endif //ICOMPONENT_HPP
