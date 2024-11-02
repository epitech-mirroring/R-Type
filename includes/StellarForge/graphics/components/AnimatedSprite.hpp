/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** AnimatedSprite.hpp
**/

#ifndef ANIMATEDSPRITE_HPP
#define ANIMATEDSPRITE_HPP
#include <glm/vec2.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "IGraphicsComponent.hpp"
#include "common/components/AComponent.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"

/**
 * @class AnimatedSprite
 * @brief This class is used to create an animated sprite.
 * @details AnimatedSprite handles sprite animation, allowing a series of frames to be displayed in a sequence with a specified frame rate.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class AnimatedSprite final : public AComponent, IGraphicsComponent {
public:
 /**
  * @brief Constructor for the AnimatedSprite class.
  * @param owner The owner of the component, of type IObject*.
  * @param path The file path to the sprite image as a string.
  * @param frames A vector of sf::IntRect objects representing the frames for the animation.
  * @param frameTime The time duration each frame is displayed, with a default of 0.1 seconds.
  * @param currentFrame The initial frame index, defaulting to 0.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 AnimatedSprite(IObject *owner, const std::string &path,
                const std::vector<sf::IntRect> &frames,
                float frameTime = 0.1f, unsigned int currentFrame = 0);

 AnimatedSprite(IObject *owner, const json::JsonObject *data);

 /**
  * @brief Destructor for the AnimatedSprite class.
  * @details Cleans up and releases resources used by the AnimatedSprite.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 ~AnimatedSprite() override = default;

 /**
  * @brief Renders the animated sprite on the screen using the provided window.
  * @param window A pointer to the sf::RenderWindow object used for rendering.
  * @details This method renders the animated sprite on the screen at the specified position using the provided window.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void render(sf::RenderWindow *window) override;

 /**
  * @brief Updates the animation frame based on the frame time.
  * @details This method updates the current frame of the animation based on the frame time.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void runComponent() override;

 /**
  * @brief Sets the texture of the animated sprite to the specified file path.
  * @param path The file path to the new sprite image.
  * @details This method loads the texture from the specified file path and sets it as the new sprite texture.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setTexture(const std::string &path);

 /**
  * @brief Sets the frames for the animation.
  * @param frames A vector of sf::IntRect objects representing the frames for the animation.
  * @details This method sets the frames for the animation to the specified vector of sf::IntRect objects.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setFrames(std::vector<sf::IntRect> frames);

 /**
  * @brief Sets the current frame of the animation.
  * @param frame The index of the frame to set as the current frame.
  * @details This method sets the current frame of the animation to the specified index.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setFrame(unsigned int frame);

 /**
  * @brief Moves to the next frame in the animation sequence.
  * @details This method advances the animation to the next frame in the sequence.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void nextFrame();

 /**
  * @brief Moves to the previous frame in the animation sequence.
  * @details This method moves the animation to the previous frame in the sequence.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void prevFrame();

 /**
  * @brief Sets the frame time for the animation.
  * @param frameTime The time duration each frame is displayed.
  * @details This method sets the frame time for the animation, specifying the duration each frame is displayed on the screen.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setFrameTime(float frameTime);

 /**
  * @brief Gets the size of the animated sprite on the screen.
  * @return The size of the animated sprite as a glm::vec2.
  * @details This method returns the size of the animated sprite on the screen as a glm::vec2, where x is the width and y is the height.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 glm::vec2 getSize() override;


 /**
  * @class Meta
  * @brief The metaclass for the AnimatedSprite class.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 class Meta final : public IMeta {
 protected:
  AnimatedSprite *_owner;
  InvisibleFieldGroup _fieldGroup;

 public:
  explicit Meta(AnimatedSprite *owner);

  ~Meta() override = default;

  [[nodiscard]] std::string getName() const override;

  [[nodiscard]] std::string getDescription() const override;

  [[nodiscard]] bool isUnique() const override;

  [[nodiscard]] bool canBeRemoved() const override;

  [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
 };

 [[nodiscard]] json::IJsonObject *serializeData() override;

 void deserialize(const json::IJsonObject *data) override;

 AnimatedSprite *clone(IObject *owner) const override;

private:
 sf::Texture texture; /**< The texture of the animated sprite. */
 sf::Sprite sprite; /**< The sprite object to render. */
 std::vector<sf::IntRect> frames; /**< The frames for the animation. */
 unsigned int currentFrame; /**< The current frame index in the animation. */
 float frameTime; /**< Time duration each frame is displayed. */
 sf::Clock clock; /**< Internal clock to control frame timing. */
 std::string path; /**< The file path to the sprite image. */
};

#endif //ANIMATEDSPRITE_HPP
