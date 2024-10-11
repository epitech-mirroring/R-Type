/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef PHYSICS_HPP
#define PHYSICS_HPP
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

/**
 * @typedef Vector3
 * @brief A type alias for glm::vec3, representing a 3D vector.
 * @version v0.1.0
 * @since v0.1.0
 * @author Landry GIGANT
 */
using Vector3 = glm::vec3;

/**
 * @class Physics
 * @brief A class that represents the physics of an object in a 3D space.
 * @version v0.1.0
 * @since v0.1.0
 * @author Landry GIGANT
 */
class Physics {
public:
 /**
  * @class Movement
  * @brief A nested class within Physics that provides static methods for applying physics principles.
  * @details The methods in this class can be used to apply movement, drag, force, and impulse to an object.
  * @version v0.1.0
  * @since v0.1.0
  * @author Landry GIGANT
  */
 class Movement {
 public:
  /**
   * @brief Apply movement to an object based on its current position, velocity, and a time delta.
   * @param pos The current position of the object.
   * @param vel The current velocity of the object.
   * @param deltaTime The time delta to apply.
   * @version v0.1.0
   * @since v0.1.0
   * @author Landry GIGANT
   */
  static void applyMovement(Vector3 &pos, const Vector3 &vel, float deltaTime);

  /**
   * @brief Apply movement to an object based on its current position, velocity, acceleration, and a time delta.
   * @param pos The current position of the object.
   * @param vel The current velocity of the object.
   * @param acc The current acceleration of the object.
   * @param deltaTime The time delta to apply.
   * @version v0.1.0
   * @since v0.1.0
   * @author Landry GIGANT
   */
  static void applyMovement(Vector3 &pos, Vector3 &vel, const Vector3 &acc,
                            float deltaTime);

  /**
   * @brief Apply movement to an object based on its current position, velocity, acceleration, terminal velocity, and a time delta.
   * @param pos The current position of the object.
   * @param vel The current velocity of the object.
   * @param acc The current acceleration of the object.
   * @param terminalVelocity The terminal velocity of the object.
   * @param deltaTime The time delta to apply.
   * @version v0.1.0
   * @since v0.1.0
   * @author Landry GIGANT
   */
  static void applyMovement(Vector3 &pos, Vector3 &vel, const Vector3 &acc,
                            float terminalVelocity, float deltaTime);

  /**
   * @brief Apply drag to an object based on its current velocity, a drag coefficient, and a time delta.
   * @param vel The current velocity of the object.
   * @param drag The drag coefficient to apply.
   * @param deltaTime The time delta to apply.
   * @version v0.1.0
   * @since v0.1.0
   * @author Landry GIGANT
   */
  static void applyDrag(Vector3 &vel, float drag, float deltaTime);

  /**
   * @brief Apply a force to an object based on its current velocity, the force to apply, and a time delta.
   * @param vel The current velocity of the object.
   * @param force The force to apply.
   * @param deltaTime The time delta to apply.
   * @version v0.1.0
   * @since v0.1.0
   * @author Landry GIGANT
   */
  static void applyForce(Vector3 &vel, const Vector3 &force, float deltaTime);

  /**
   * @brief Apply an impulse to an object based on its current velocity and the impulse to apply.
   * @param vel The current velocity of the object.
   * @param impulse The impulse to apply.
   * @version v0.1.0
   * @since v0.1.0
   * @author Landry GIGANT
   */
  static void applyImpulse(Vector3 &vel, const Vector3 &impulse);
 };
};


#endif //PHYSICS_HPP
