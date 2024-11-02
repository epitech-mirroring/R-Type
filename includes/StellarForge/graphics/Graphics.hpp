/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "common/IScene.hpp"
#include "common/IObject.hpp"
#include "GraphicsException.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#ifndef __APPLE__
#include <memory>
#endif
#include <functional>

/**
 * @class Graphics
 * @brief This class handles all graphics-related operations.
 * @details The Graphics class is responsible for initializing and managing the rendering
 *          of objects in the scenes, managing an internal list of objects to render. The 
 *          objects are sorted by their z-index for proper rendering order.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class Graphics {
public:
 /**
  * @brief Constructor for the Graphics class.
  * @param width The width of the window.
  * @param height The height of the window.
  * @param title The title of the window. Default is "Game".
  * @param precharge Whether to preload all objects in all scenes. Default is false.
  * @details This prepares the window with the specified dimensions and title,
  *          and optionally precharges all objects if the precharge flag is set to true.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 Graphics(int width, int height, const std::string &title = "Game",
          bool precharge = false);

 /**
  * @brief Destructor for the Graphics class.
  * @details Cleans up and releases all resources used by the Graphics class, including
  *          the SDL window and renderer.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 ~Graphics();

 /**
  * @brief Renders the objects in the current scene.
  * @param updateFunction A function to update the object before rendering.
     * @details This method renders all objects in the current scene in the correct order
  *         based on their z-index. It should be called once per frame to render the
  *        scene.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void render(const std::function<void(IObject *)> &updateFunction);

 /**
     * @brief Translates an SFM key code to a string.
     * @param key The SFML key code to translate.
     * @return The string representation of the key in lowercase and spaces replaced with dashes.
     * @details This method translates an SFML key code to a string representation of the key.
     * @since v0.1.0
     * @author Aubane NOURRY
     */
 static std::string keyToString(sf::Keyboard::Key key);

 /**
  * @brief Checks for and handles any events.
  * @details This method checks for any events that have occurred since the last frame
  *         and handles them accordingly.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void catchEvents();

 /**
* @brief Clears the current rendering target.
* @details Clears the renderer's drawing surface, typically called at the beginning of a frame
*          before rendering the objects.
* @since v0.1.0
* @author Aubane NOURRY
*/
 void clear();

 /**
  * @brief Presents the rendered frame to the window.
  * @details This method is called at the end of the rendering process to present the
  *          rendered frame on the screen.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void present();

 /**
  * @brief Closes the graphics system.
  * @details Releases all resources used by the graphics system, closes the window
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void close();

 /**
  * @brief Adds an object to the sorted object list and maintains the correct order.
  * @param object A shared pointer to the object to add.
  * @details This method adds an object to the internal sortedObjects list and ensures
  *          that the objects are kept in the correct rendering order based on their
  *          z-index. If the object is already in the list, it won't be added again.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void addAndSortObject(IObject *object);

 /**
  * @brief Changes the current scene to the specified scene.
  * @param scene A pointer to the scene to set as the current scene.
  * @details This method changes the current scene to the specified scene and sets the
  *         scene's objects to be rendered in the correct order.
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setScene(IScene *scene);

private:
 sf::RenderWindow window; /**< The SDL window used for rendering. */
 int width; /**< The width of the window. */
 int height; /**< The height of the window. */
 const std::string title; /**< The title of the window. */
 bool prepared; /**< Flag indicating if the graphics system is prepared. */
 std::vector<IObject *> sortedObjects;
 /**< List of objects sorted by z-index for rendering. */
 bool precharge;
 /**< Flag to indicate if all objects should be preloaded in all scenes. */
 IScene *currentScene; /**< The current scene being rendered. */
 std::vector<sf::Keyboard::Key> keysPressed; /**< The keys currently pressed. */
};

#endif // GRAPHICS_HPP
