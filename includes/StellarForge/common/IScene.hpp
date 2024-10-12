/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

#include "IObject.hpp"
#include <vector>

/**
 * @class IScene
 * @brief This is the interface for the scene class.
 * @version v0.1.0
 * @since v0.1.0
 * @author Axel ECKENBERG
 */
class IScene {
public:
 /**
  * @brief The destructor of the scene
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual ~IScene() = default;

 /**
  * @brief This function is used to run the scene
  * @note This is intended to be called once per frame
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void runScene() = 0;

 /**
  * @brief Get all the objects in the scene
  * @return The objects in the scene
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 [[nodiscard]]
 virtual std::vector<IObject *> getObjects() const = 0;

 /**
  * @brief Add an object to the scene
  * @param object The object to add
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void addObject(IObject *object) = 0;

 /**
  * @brief Remove an object from the scene
  * @param object The object to remove
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 virtual void removeObject(IObject *object) = 0;
};


#endif //ISCENE_HPP
