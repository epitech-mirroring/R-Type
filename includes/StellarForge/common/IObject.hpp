/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef IOBJECT_HPP
#define IOBJECT_HPP
#include "IComponent.hpp"
#include <optional>
#include <string>
#include <vector>

/**
 * @class IObject
 * @brief This is the interface for the object class.
 * @details This class is used to create objects that can have components and children.
 * @version v0.1.0
 * @since v0.1.0
 * @author Axel ECKENBERG
 */
class IObject {
public:
 /**
  * @brief The destructor of the object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual ~IObject() = default;

 /**
  * @brief The copy constructor of the object
  * @param other The object to copy
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 IObject(const IObject &other) = default;

 /**
  * @brief The copy assignment operator of the object
  * @param other The object to copy
  * @return The new object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 IObject &operator=(const IObject &other) = default;

 /**
  * @brief The comparison operator of the object
  * @param other The object to compare
  * @return True if the objects are the same, false otherwise
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 virtual bool operator==(const IObject &other) const = 0;

 /**
  * @brief Clone the object
  * @warning The object cloned will have the same components and children as the original object
  * but also all the same values.
  * @return The new object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 [[nodiscard]]
 virtual IObject *clone() const = 0;

 /**
  * @brief Returns all the components of the object
  * @return A vector of pointers to components. Should not be empty
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 [[nodiscard]]
 virtual std::vector<IComponent *> getComponents() const = 0;

 /**
  * @brief Returns all the children of the object
  * @return A vector of pointers to objects. Can be empty
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 [[nodiscard]]
 virtual std::vector<IObject *> getChildren() const = 0;

 /**
  * @brief Returns the parent of the object if it has one
  * or an empty optional if it does not have a parent
  * @return An optional pointer to the parent object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 [[nodiscard]]
 virtual std::optional<IObject *> getParent() const = 0;

 /**
  * @brief Sets the parent of the object
  * @warning This will remove the object from its current parent if it had one
  * but the old pointer will still be valid and the object will still have the same children
  * @param parent The new parent of the object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void setParent(IObject *parent) = 0;

 /**
  * @brief Adds a child to the object.
  * @warning This will also set the parent of the child to this object
  * @param child The object to add as a child
  * @see IObject::setParent
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void addChild(IObject *child) = 0;

 /**
  * @brief Removes a child from the object.
  * @warning This will also set the parent of the child to an empty optional
  * @param child The object to remove as a child
  * @see IObject::setParent
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void removeChild(IObject *child) = 0;

 /**
  * @brief Adds a component to the object.
  * @param component The component to add to the object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void addComponent(IComponent *component) = 0;

 /**
  * @brief This removes the specified component from the object.
  * @param component The component to remove from the object
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void removeComponent(IComponent *component) = 0;

 /**
  * @brief This function is used to run the object logic.
  * @details This is meant to be called every frame.
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void runObject() = 0;

 /**
  * @brief This function is used to check if the object is active.
  * @return True if the object is active, false otherwise
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 virtual bool isActive() = 0;

 /**
  * @class IMeta
  * @brief This is the interface for the object's meta class.
  * @details This class is used to get all the meta information of the object.
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 class IMeta {
 public:
  /**
   * @brief The destructor of the object's meta
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  virtual ~IMeta() = default;

  /**
   * @brief The copy constructor of the object's meta
   * @details Is deleted because the object's meta should not be copied
   * @param other The object's meta to copy
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  IMeta(const IMeta &other) = delete;

  /**
   * @brief The copy assignment operator of the object's meta
   * @details Is deleted because the object's meta should not be copied
   * @param other The object's meta to copy
   * @return The new object's meta
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  IMeta &operator=(const IMeta &other) = delete;

  /**
   * @brief The move constructor of the object's meta
   * @details Is deleted because the object's meta should not be moved
   * @param other The object's meta to move
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  IMeta(IMeta &&other) = delete;

  /**
   * @brief The move assignment operator of the object's meta
   * @details Is deleted because the object's meta should not be moved
   * @param other The object's meta to move
   * @return The moved object's meta
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  IMeta &operator=(IMeta &&other) = delete;

  /**
   * @brief This function is used to get the name of the object
   * @return The name of the object
   * @version v0.1.0
   * @since v0.1.0
   * @author Axel ECKENBERG
   */
  [[nodiscard]]
  virtual std::string getName() const = 0;
 };

 /**
 * @brief Gives the meta of the object
 * @return The meta of the object
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
 [[nodiscard]] virtual IMeta &getMeta() const = 0;
};

#endif //IOBJECT_HPP
