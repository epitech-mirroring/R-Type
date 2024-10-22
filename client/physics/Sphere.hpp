/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
*/

#ifndef STELLARFORGE_SPHERE_HPP
#define STELLARFORGE_SPHERE_HPP

#include "Collider.hpp"

/**
 * @class Sphere
 * @brief A class that represents a sphere in 3D space.
 * @details This class contains the position and radius of the sphere.
 * @version v0.1.0
 * @since v0.1.0
 * @author Landry GIGANT
 */
class Sphere : public ICollider {
public:
    /**
     * @brief The position of the sphere in 3D space.
     */
    Vector3 position;

    /**
     * @brief The radius of the sphere.
     */
    float radius;

    /**
     * @brief Constructor for the Sphere class.
     * @param position The position of the sphere in 3D space.
     * @param radius The radius of the sphere.
     */
    Sphere(Vector3 position, float radius);

    /**
     * @brief Check if the sphere collides with another collider.
     * @param collider The collider to check for collision.
     * @return True if the sphere collides with the collider, false otherwise.
     */
    bool collide(ICollider *collider) override;
};

#endif //STELLARFORGE_SPHERE_HPP
