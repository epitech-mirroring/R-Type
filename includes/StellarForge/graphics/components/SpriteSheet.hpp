/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** SpriteSheet.hpp
**/

#ifndef SPRITESHEET_HPP
#define SPRITESHEET_HPP
#include "IGraphicsComponent.hpp"
#include "common/components/AComponent.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"

/**
 * @class SpriteSheet
 * @brief A class that represents a sprite sheet, allowing the rendering of individual frames from a sprite sheet texture.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class SpriteSheet final : public AComponent, IGraphicsComponent {
public:
 /**
  * @brief Constructor for the SpriteSheet class.
  * @param owner The owner of the component, of type IObject*.
  * @param path The file path to the sprite sheet image, as a string.
  * @param frames A vector of sf::IntRect representing frames in the sprite sheet.
  * @param frame The index of the initial frame to display, default is 0.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 SpriteSheet(IObject *owner, const std::string &path,
             const std::vector<sf::IntRect> &frames,
             unsigned int frame = 0);

 SpriteSheet(IObject *owner, const json::JsonObject *data);

 /**
  * @brief Destructor for the SpriteSheet class.
  * @details Cleans up and releases resources used by the SpriteSheet.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 ~SpriteSheet() override = default;

 /**
  * @brief Renders the sprite sheet on the screen using the provided window.
  * @param window A pointer to the sf::RenderWindow object used for rendering.
  * @details This method renders the sprite sheet on the screen at the specified position using the provided window.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void render(sf::RenderWindow *window) override;

 /**
  * @brief Sets the texture of the sprite sheet to the specified file path.
  * @param path The file path to the new sprite sheet image.
  * @details This method loads the texture from the specified file path and sets it as the new sprite sheet texture.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setTexture(const std::string &path);

 /**
  * @brief Sets the frames for the sprite sheet.
  * @param frames A vector of sf::IntRect representing the frames in the sprite sheet.
  * @details This method sets the frames for the sprite sheet, allowing individual frames to be displayed.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setFrames(std::vector<sf::IntRect> frames);

 /**
  * @brief Sets the current frame of the sprite sheet.
  * @param frame The index of the frame to display.
  * @details This method sets the current frame of the sprite sheet to the specified index.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setFrame(unsigned int frame);

 /**
  * @brief Moves to the next frame in the sprite sheet sequence.
  * @details This method advances the sprite sheet to the next frame in the sequence.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void nextFrame();

 /**
  * @brief Moves to the previous frame in the sprite sheet sequence.
  * @details This method moves the sprite sheet to the previous frame in the sequence.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void prevFrame();

 /**
  * @brief Gets the size of the sprite sheet on the screen.
  * @return The size of the sprite sheet as a glm::vec2.
  * @details This method returns the size of the sprite sheet on the screen as a glm::vec2, where x is the width and y is the height.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 glm::vec2 getSize() override;

 void runComponent() override;

 /**
  * @class Meta
  * @brief The metaclass for the SpriteSheet class
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 class Meta final : public IMeta {
 protected:
  SpriteSheet *_owner;
  InvisibleFieldGroup _fieldGroup;

 public:
  explicit Meta(SpriteSheet *owner);

  [[nodiscard]] std::string getName() const override;

  [[nodiscard]] std::string getDescription() const override;

  [[nodiscard]] bool isUnique() const override;

  [[nodiscard]] bool canBeRemoved() const override;

  [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
 };

 [[nodiscard]] json::IJsonObject *serializeData() override;

 void deserialize(const json::IJsonObject *data) override;

 [[nodiscard]] SpriteSheet *clone(IObject *owner) const override;

private:
 sf::Texture texture; /**< The texture of the sprite sheet. */
 sf::Sprite sprite; /**< The sprite object to render. */
 std::vector<sf::IntRect> frames; /**< The frames from the sprite sheet. */
 unsigned int currentFrame; /**< The current frame index. */
 std::string path; /**< The file path to the sprite sheet image. */
};

#endif //SPRITESHEET_HPP
