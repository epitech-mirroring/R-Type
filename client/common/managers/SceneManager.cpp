/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** SceneManager.cpp
*/

#include <algorithm>
#include "SceneManager.hpp"
#include "ManagerException.hpp"

SceneManager &SceneManager::getInstance() {
    static SceneManager instance;
    return instance;
}

void SceneManager::addScene(const UUID &uuid,
                            IScene *scene,
                            const int position) {
    if (isSceneExist(uuid)) {
        throw ManagerException(
            "Scene with UUID " + uuid.getUuidString() + " already exists.");
    }
    _scenes[uuid] = scene;
    if (position == -1) {
        _sceneOrder.push_back(uuid);
    } else {
        _sceneOrder.insert(
            _sceneOrder.begin() + std::min(position,
                                           static_cast<int>(_sceneOrder.size())),
            uuid);
    }
    if (_currentSceneIndex == -1) {
        _currentSceneIndex = 0;
    }
}

void SceneManager::addScene(IScene *scene,
                            int position) {
    UUID uuid;
    uuid.generateUuid();
    addScene(uuid, scene, position);
}

void SceneManager::removeScene(const UUID &uuid) {
    const auto scene = std::find(_sceneOrder.begin(), _sceneOrder.end(), uuid);
    if (scene != _sceneOrder.end()) {
        _sceneOrder.erase(scene);

        if (_sceneOrder.empty()) {
            _currentSceneIndex = -1;
        } else if (_currentSceneIndex >= _sceneOrder.size()) {
            _currentSceneIndex = static_cast<int>(_sceneOrder.size()) - 1;
        }
    } else {
        throw ManagerException(
            "Scene with UUID " + uuid.getUuidString() + " not found in order.");
    }

    _scenes.erase(uuid);
}

void SceneManager::switchToScene(const UUID &uuid) {
    const auto scene = std::find(_sceneOrder.begin(), _sceneOrder.end(), uuid);
    if (scene != _sceneOrder.end()) {
        _currentSceneIndex = static_cast<int>(std::distance(
            _sceneOrder.begin(), scene));
    } else {
        throw ManagerException(
            "Scene with UUID " + uuid.getUuidString() + " does not exist.");
    }
}

void SceneManager::switchToNextScene() {
    if (_currentSceneIndex >= 0 && _currentSceneIndex < _sceneOrder.size() -
        1) {
        _currentSceneIndex++;
    } else {
        throw ManagerException("No next scene available.");
    }
}

void SceneManager::switchToPreviousScene() {
    if (_currentSceneIndex > 0) {
        _currentSceneIndex--;
    } else {
        throw ManagerException("No previous scene available.");
    }
}

void SceneManager::switchScenesOrder(const UUID &uuid1, const UUID &uuid2) {
    const auto it1 = std::find(_sceneOrder.begin(), _sceneOrder.end(), uuid1);
    const auto it2 = std::find(_sceneOrder.begin(), _sceneOrder.end(), uuid2);

    if (it1 != _sceneOrder.end() && it2 != _sceneOrder.end()) {
        std::iter_swap(it1, it2);
    } else {
        throw ManagerException("One or both scenes not found.");
    }
}

IScene *SceneManager::getCurrentScene() const {
    if (_currentSceneIndex >= 0 && _currentSceneIndex < _sceneOrder.size()) {
        return _scenes.at(_sceneOrder[_currentSceneIndex]);
    }
    throw ManagerException("No current scene available.");
}

IScene *SceneManager::getSceneById(const UUID &uuid) const {
    const auto scene = _scenes.find(uuid);
    if (scene != _scenes.end()) {
        return scene->second;
    }
    throw ManagerException(
        "Scene with UUID " + uuid.getUuidString() + " not found.");
}

std::map<UUID, IScene *> SceneManager::getScenes() const {
    return _scenes;
}

std::vector<UUID> SceneManager::getSceneOrder() const {
    return _sceneOrder;
}

void SceneManager::clearScenes() {
    _scenes.clear();
    _sceneOrder.clear();
    _currentSceneIndex = -1;
}

bool SceneManager::isSceneExist(const UUID &uuid) const {
    return _scenes.find(uuid) != _scenes.end();
}
