/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
*/

#ifndef STELLARFORGE_BOX_HPP
#define STELLARFORGE_BOX_HPP

#include "Collider.hpp"

/**
* @class Box
* @brief A class that represents a box in 3D space.
* @details This class contains the position and size of the box.
* @version v0.1.0
* @since v0.1.0
* @author Landry GIGANT
*/
class Box final : public ICollider {
public:
 /**
  * @brief The position of the box in 3D space.
  */
 Vector3 position;

 /**
  * @brief The size of the box in 3D space.
  */
 Vector3 size;

 /**
  * @brief Constructor for the Box class.
  * @param position The position of the box in 3D space.
  * @param size The size of the box in 3D space.
  */
 Box(Vector3 position, Vector3 size);

 /**
  * @brief Check if the box collides with another collider.
  * @param collider The collider to check for collision.
  * @return True if the box collides with the collider, false otherwise.
  */
 bool collide(ICollider *collider) override;
};

#endif //STELLARFORGE_BOX_HPP
