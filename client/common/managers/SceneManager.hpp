/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** SceneManager.hpp
*/

#pragma once

#include <map>
#include <vector>
#include "../IScene.hpp"
#include "../UUID.hpp"

/**
 * @class SceneManager
 * @brief Manages scenes in the StellarForge engine.
 * @details This class provides an interface for managing multiple scenes in the application. It allows adding, removing, and switching between scenes.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class SceneManager {
public:
 /**
  * @brief Retrieves the singleton instance of SceneManager.
  * @return The single instance of SceneManager.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
 */
 static SceneManager &getInstance();
 /**
  * @brief Adds a scene to the manager.
  * @param uuid The unique identifier of the scene.
  * @param scene A pointer to the scene to be added.
  * @param position The position to add the scene at. Default is -1, which appends the scene.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void addScene(const UUID &uuid, IScene *scene,
               int position = -1);

 /**
  * @brief Adds a scene to the manager and generates a UUID for it.
  * @param scene A pointer to the scene to be added.
  * @param position The position to add the scene at. Default is -1, which appends the scene.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void addScene(IScene *scene, int position = -1);

 /**
  * @brief Removes a scene from the manager.
  * @param uuid The unique identifier of the scene to be removed.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void removeScene(const UUID &uuid);

 /**
  * @brief Switches to a specific scene.
  * @param uuid The unique identifier of the scene to switch to.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void switchToScene(const UUID &uuid);

 /**
  * @brief Switches to the next scene in the order.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void switchToNextScene();

 /**
  * @brief Switches to the previous scene in the order.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void switchToPreviousScene();

 /**
  * @brief Switches the order of two scenes.
  * @param uuid1 The unique identifier of the first scene.
  * @param uuid2 The unique identifier of the second scene.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void switchScenesOrder(const UUID &uuid1, const UUID &uuid2);

 /**
  * @brief Gets the current scene.
  * @return A pointer to the current scene.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 [[nodiscard]] IScene *getCurrentScene() const;

 /**
  * @brief Retrieves a scene by its unique identifier.
  * @param uuid The unique identifier of the scene.
  * @return A pointer to the scene.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 [[nodiscard]] IScene *getSceneById(const UUID &uuid) const;

 /**
  * @brief Clears all scenes managed by the SceneManager.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void clearScenes();

 /**
  * @brief Retrieves all the scenes managed by the SceneManager.
  * @return A map of UUIDs and pointers to the scenes.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 [[nodiscard]] std::map<UUID, IScene *> getScenes() const;

 /**
  * @brief Retrieves the order of the scenes.
  * @return A vector of UUIDs representing the order of the scenes.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 [[nodiscard]] std::vector<UUID> getSceneOrder() const;

 /**
  * @brief Checks if a scene exists in the SceneManager.
  * @param uuid The unique identifier of the scene.
  * @return True if the scene exists, false otherwise.
  * @version v0.1.0
  * @since v0.1.0
  * @author Axel ECKENBERG
  */
 [[nodiscard]]
 bool isSceneExist(const UUID &uuid) const;

private:
 /**
  * @brief Default constructor for SceneManager private to prevent creation.
  * @details Initializes the SceneManager with no scenes.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 SceneManager() = default;

 /**
  * @brief Destructor for SceneManager private to prevent deletion.
  * @details Cleans up the SceneManager when it is no longer in use.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 ~SceneManager() = default;

 std::map<UUID, IScene *> _scenes; ///< Map of UUIDs to scenes.
 std::vector<UUID> _sceneOrder; ///< Order of the scenes.
 int _currentSceneIndex{-1}; ///< The index of the current scene.
};
