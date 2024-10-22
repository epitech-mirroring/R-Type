/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
*/

#include "Transform.hpp"

#include "common/fields/Vector3Field.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"
#include "common/json/JsonNumber.hpp"
#include "common/json/JsonObject.hpp"

Transform::Transform(IObject *owner, const json::JsonObject *data): AComponent(
        owner, new Meta(this), data), _position(Vector3(0, 0, 0)),
    _rotation(glm::quat(1, 0, 0, 0)), _scale(Vector3(1, 1, 1)) {
}

Transform::Transform(IObject *owner, const Vector3 pos, const glm::quat rot,
                     const Vector3 scale): AComponent(owner, new Meta(this)),
                                           _position(pos),
                                           _rotation(rot), _scale(scale) {
}

Vector3 Transform::getPosition() const {
    return this->_position;
}

glm::quat Transform::getRotation() const {
    return this->_rotation;
}

Vector3 Transform::getScale() const {
    return this->_scale;
}

void Transform::setPosition(const Vector3 pos) {
    this->_position = pos;
}

void Transform::translate(const Vector3 pos) {
    this->_position += pos;
}

void Transform::setRotation(const glm::quat rot) {
    this->_rotation = rot;
}

void Transform::rotate(const Vector3 axis, const float angle) {
    this->_rotation = glm::rotate(this->_rotation, angle, axis);
}

void Transform::setScale(const Vector3 scale) {
    this->_scale = scale;
}

void Transform::scaleBy(const Vector3 scale) {
    this->_scale *= scale;
}

Transform::Meta::Meta(Transform *owner): _owner(owner),
                                         _fieldGroup(InvisibleFieldGroup({})) {
    const std::vector<IField *> fields = {
        new Vector3Field("Position", "The position of the object",
                         [this](const Vector3 &pos) {
                             this->_owner->_position = pos;
                         }, [this]() {
                             return this->_owner->_position;
                         }),
        new Vector3Field("Rotation", "The rotation of the object",
                         [this](const Vector3 &rot) {
                             this->_owner->_rotation = glm::quat(rot);
                         }, [this]() {
                             return eulerAngles(this->_owner->_rotation);
                         }),
        new Vector3Field("Scale", "The scale of the object",
                         [this](const Vector3 &scale) {
                             this->_owner->_scale = scale;
                         }, [this]() {
                             return this->_owner->_scale;
                         })
    };
    this->_fieldGroup = InvisibleFieldGroup(fields);
}

void Transform::runComponent() {
}

std::string Transform::Meta::getName() const {
    return "Transform";
}

std::string Transform::Meta::getDescription() const {
    return
            "The Transform component is used to store the position, rotation and scale of an object.";
}

bool Transform::Meta::isUnique() const {
    return true;
}

bool Transform::Meta::canBeRemoved() const {
    return false;
}

std::vector<const IComponent::IMeta::IFieldGroup *>
Transform::Meta::getFieldGroups() const {
    return {&_fieldGroup};
}

json::IJsonObject *Transform::serializeData() {
    auto *object = new json::JsonObject("data");
    auto *position = new json::JsonObject("position");
    auto *rotation = new json::JsonObject("rotation");
    auto *scale = new json::JsonObject("scale");
    position->add(new json::JsonNumber(this->_position.x, "x"));
    position->add(new json::JsonNumber(this->_position.y, "y"));
    position->add(new json::JsonNumber(this->_position.z, "z"));
    const glm::vec3 euler = eulerAngles(this->_rotation);
    rotation->add(new json::JsonNumber(euler.x, "x"));
    rotation->add(new json::JsonNumber(euler.y, "y"));
    rotation->add(new json::JsonNumber(euler.z, "z"));
    scale->add(new json::JsonNumber(this->_scale.x, "x"));
    scale->add(new json::JsonNumber(this->_scale.y, "y"));
    scale->add(new json::JsonNumber(this->_scale.z, "z"));
    object->add(position);
    object->add(rotation);
    object->add(scale);
    return object;
}

void Transform::deserialize(const json::IJsonObject *data) {
    if (data != nullptr && data->getType() == json::OBJECT) {
        const auto *obj = dynamic_cast<const json::JsonObject *>(data);
        if (obj->contains("position")) {
            this->_position = glm::vec3(
                obj->getValue<json::JsonObject>("position")->getValue<
                    json::JsonNumber>("x")->getFloatValue(),
                obj->getValue<json::JsonObject>("position")->getValue<
                    json::JsonNumber>("y")->getFloatValue(),
                obj->getValue<json::JsonObject>("position")->getValue<
                    json::JsonNumber>("z")->getFloatValue()
            );
        }
        if (obj->contains("rotation")) {
            this->_rotation = glm::quat(glm::vec3(
                obj->getValue<json::JsonObject>("rotation")->getValue<
                    json::JsonNumber>("x")->getFloatValue(),
                obj->getValue<json::JsonObject>("rotation")->getValue<
                    json::JsonNumber>("y")->getFloatValue(),
                obj->getValue<json::JsonObject>("rotation")->getValue<
                    json::JsonNumber>("z")->getFloatValue()
            ));
        }
        if (obj->contains("scale")) {
            this->_scale = glm::vec3(
                obj->getValue<json::JsonObject>("scale")->getValue<json::JsonNumber>("x")
                ->getFloatValue(),
                obj->getValue<json::JsonObject>("scale")->getValue<json::JsonNumber>("y")
                ->getFloatValue(),
                obj->getValue<json::JsonObject>("scale")->getValue<json::JsonNumber>("z")
                ->getFloatValue()
            );
        }
    }
}

Vector3 &Transform::getPosition() {
    return this->_position;
}

glm::quat &Transform::getRotation() {
    return this->_rotation;
}

Vector3 &Transform::getScale() {
    return this->_scale;
}

Transform *Transform::clone(IObject *owner) const {
    return new Transform(owner, this->_position,
                         this->_rotation, this->_scale);
}
