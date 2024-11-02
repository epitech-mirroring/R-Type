/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
*/

#ifndef STELLARFORGE_COLLIDER_HPP
#define STELLARFORGE_COLLIDER_HPP

#include <glm/glm.hpp>

using Vector3 = glm::vec3;

/**
 * @class ICollider
 * @brief Interface for colliders in the physics system.
 * @version v0.1.0
 * @since v0.1.0
 * @details This interface defines the basic structure for colliders, including a method to check for collisions.
 * @author Landry GIGANT
 */
class ICollider {
public:
    /**
     * @brief Virtual destructor for the ICollider interface.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry GIGANT
     */
    virtual ~ICollider() = default;

    /**
     * @brief Check if this collider collides with another collider.
     * @param collider Pointer to the other collider.
     * @return True if the colliders collide, false otherwise.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry GIGANT
     */
    virtual bool collide(ICollider *collider) = 0;
};

#endif //STELLARFORGE_COLLIDER_HPP
