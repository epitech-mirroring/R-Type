/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** Transform.hpp
*/

#ifndef STELLARFORGE_TRANSFORM_HPP
#define STELLARFORGE_TRANSFORM_HPP

#include "../IComponent.hpp"
#include "../fields/Vector3Field.hpp"
#include "../fields/FieldGroup.hpp"
#include "../AMeta.hpp"
#include "../AComponent.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/vec3.hpp>

using Vector3 = glm::vec3;

/**
 * @class Transform
 * @brief Represents the transformation (position, rotation, scale) of an object in 3D space.
 * @version v0.1.0
 * @since v0.1.0
 * @author Landry GIGANT
 */
class Transform : public AComponent {
private:
    Vector3 position; ///< The position of the object in 3D space.
    glm::quat rotation; ///< The rotation of the object represented as a quaternion.
    Vector3 scale; ///< The scale of the object in 3D space.

public:
    /**
     * @class TransformMeta
     * @brief Metadata class for the Transform component.
     * @version v0.1.0
     * @since v0.1.0
     */
    class TransformMeta : public AMeta {
    private:
        /**
         * @class FieldGroup
         * @brief Field group class for the TransformMeta.
         * @version v0.1.0
         * @since v0.1.0
         */
        class TransformFieldGroup : public InvisibleFieldGroup {
        public:
            /**
             * @brief Constructor for FieldGroup.
             * Initializes the field group with position, rotation, and scale fields.
             * @version v0.1.0
             * @since v0.1.0
             */
            TransformFieldGroup();
        };
    public:
        /**
         * @brief Constructor for TransformMeta.
         * Initializes the metadata with the name, description, and field groups.
         * @version v0.1.0
         * @since v0.1.0
         */
        TransformMeta();
    };

    /**
     * @brief Constructor for Transform.
     * @param owner Pointer to the owner object.
     * Initializes the Transform component with default position, rotation, and scale.
     * @version v0.1.0
     * @since v0.1.0
     */
    explicit Transform(IObject *owner);

    /**
     * @brief Constructor for Transform.
     * @param owner Pointer to the owner object.
     * @param pos The initial position of the object.
     * @param rot The initial rotation of the object.
     * @param sca The initial scale of the object.
     * Initializes the Transform component with the given position, rotation, and scale.
     * @version v0.1.0
     * @since v0.1.0
     */
    Transform(IObject *owner, Vector3 pos, glm::quat rot, Vector3 sca);

    /**
     * @brief Gets the position of the object.
     * @return The position as a Vector3.
     * @version v0.1.0
     * @since v0.1.0
     */
    [[nodiscard]] Vector3 getPosition() const;

    /**
     * @brief Gets the rotation of the object.
     * @return The rotation as a quaternion.
     * @version v0.1.0
     * @since v0.1.0
     */
    [[nodiscard]] glm::quat getRotation() const;

    /**
     * @brief Gets the scale of the object.
     * @return The scale as a Vector3.
     * @version v0.1.0
     * @since v0.1.0
     */
    [[nodiscard]] Vector3 getScale() const;

    /**
     * @brief Sets the position of the object.
     * @param pos The new position as a Vector3.
     * @version v0.1.0
     * @since v0.1.0
     */
    void setPosition(Vector3 pos);

    /**
     * @brief Translates the object by a given position.
     * @param pos The translation vector.
     * @version v0.1.0
     * @since v0.1.0
     */
    void translate(Vector3 pos);

    /**
     * @brief Sets the rotation of the object.
     * @param rot The new rotation as a quaternion.
     * @version v0.1.0
     * @since v0.1.0
     */
    void setRotation(glm::quat rot);

    /**
     * @brief Rotates the object around a given axis by a given angle.
     * @param axis The axis of rotation.
     * @param angle The angle of rotation in degrees.
     * @version v0.1.0
     * @since v0.1.0
     */
    void rotate(Vector3 axis, float angle);

    /**
     * @brief Sets the scale of the object.
     * @param sca The new scale as a Vector3.
     * @version v0.1.0
     * @since v0.1.0
     */
    void setScale(Vector3 sca);

    /**
     * @brief Scales the object by a given factor.
     * @param sca The scaling factor.
     * @version v0.1.0
     * @since v0.1.0
     */
    void scaleBy(Vector3 sca);
};

#endif //STELLARFORGE_TRANSFORM_HPP
