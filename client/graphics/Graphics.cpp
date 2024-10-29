/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "Graphics.hpp"

Graphics::Graphics(const int width, const int height, const std::string &title,
                   bool precharge)
    : window(sf::VideoMode(width, height), title), width(width), height(height),
      title(title), prepared(false), precharge(precharge), currentScene(nullptr) {
    if (!window.isOpen()) {
        throw GraphicsException("Failed to create window");
    }
    EventSystem::getInstance().triggerEvents("window_opened", nullptr);
    prepared = true;
    window.setFramerateLimit(60);
    sortedObjects.reserve(100);
    currentScene = SceneManager::getInstance().getCurrentScene();
    keysPressed.reserve(10);
}

Graphics::~Graphics() {
    close();
}

template <typename T>
static T *getObjComponent(IObject *object) {
    for (auto *component: object->getComponents()) {
        if (auto *comp = dynamic_cast<T *>(component)) {
            return comp;
        }
    }
    return nullptr;
}

void Graphics::addAndSortObject(IObject *object) {
    if (sortedObjects.empty()) {
        sortedObjects.push_back(object);
        return;
    }
    auto obj = std::find(sortedObjects.begin(), sortedObjects.end(), object);
    if (obj == sortedObjects.end()) {
        sortedObjects.push_back(object);
    }
}

void Graphics::clear() {
    window.clear(sf::Color::Black);
}

void Graphics::present() {
    window.display();
}

std::string Graphics::keyToString(sf::Keyboard::Key key) {
    static const std::unordered_map<sf::Keyboard::Key, std::string> keyMap = {
        {sf::Keyboard::Unknown, "unknown"},
        {sf::Keyboard::A, "a"},
        {sf::Keyboard::B, "b"},
        {sf::Keyboard::C, "c"},
        {sf::Keyboard::D, "d"},
        {sf::Keyboard::E, "e"},
        {sf::Keyboard::F, "f"},
        {sf::Keyboard::G, "g"},
        {sf::Keyboard::H, "h"},
        {sf::Keyboard::I, "i"},
        {sf::Keyboard::J, "j"},
        {sf::Keyboard::K, "k"},
        {sf::Keyboard::L, "l"},
        {sf::Keyboard::M, "m"},
        {sf::Keyboard::N, "n"},
        {sf::Keyboard::O, "o"},
        {sf::Keyboard::P, "p"},
        {sf::Keyboard::Q, "q"},
        {sf::Keyboard::R, "r"},
        {sf::Keyboard::S, "s"},
        {sf::Keyboard::T, "t"},
        {sf::Keyboard::U, "u"},
        {sf::Keyboard::V, "v"},
        {sf::Keyboard::W, "w"},
        {sf::Keyboard::X, "x"},
        {sf::Keyboard::Y, "y"},
        {sf::Keyboard::Z, "z"},
        {sf::Keyboard::Num0, "0"},
        {sf::Keyboard::Num1, "1"},
        {sf::Keyboard::Num2, "2"},
        {sf::Keyboard::Num3, "3"},
        {sf::Keyboard::Num4, "4"},
        {sf::Keyboard::Num5, "5"},
        {sf::Keyboard::Num6, "6"},
        {sf::Keyboard::Num7, "7"},
        {sf::Keyboard::Num8, "8"},
        {sf::Keyboard::Num9, "9"},
        {sf::Keyboard::Escape, "escape"},
        {sf::Keyboard::LControl, "left-control"},
        {sf::Keyboard::LShift, "left-shift"},
        {sf::Keyboard::LAlt, "left-alt"},
        {sf::Keyboard::LSystem, "left-system"},
        {sf::Keyboard::RControl, "right-control"},
        {sf::Keyboard::RShift, "right-shift"},
        {sf::Keyboard::RAlt, "right-alt"},
        {sf::Keyboard::RSystem, "right-system"},
        {sf::Keyboard::Menu, "menu"},
        {sf::Keyboard::LBracket, "left-bracket"},
        {sf::Keyboard::RBracket, "right-bracket"},
        {sf::Keyboard::SemiColon, "semicolon"},
        {sf::Keyboard::Comma, "comma"},
        {sf::Keyboard::Period, "period"},
        {sf::Keyboard::Quote, "quote"},
        {sf::Keyboard::Slash, "slash"},
        {sf::Keyboard::BackSlash, "backslash"},
        {sf::Keyboard::Tilde, "tilde"},
        {sf::Keyboard::Equal, "equal"},
        {sf::Keyboard::Dash, "dash"},
        {sf::Keyboard::Space, "space"},
        {sf::Keyboard::Return, "enter"},
        {sf::Keyboard::BackSpace, "backspace"},
        {sf::Keyboard::Tab, "tab"},
        {sf::Keyboard::PageUp, "page-up"},
        {sf::Keyboard::PageDown, "page-down"},
        {sf::Keyboard::End, "end"},
        {sf::Keyboard::Home, "home"},
        {sf::Keyboard::Insert, "insert"},
        {sf::Keyboard::Delete, "delete"},
        {sf::Keyboard::Add, "add"},
        {sf::Keyboard::Subtract, "subtract"},
        {sf::Keyboard::Multiply, "multiply"},
        {sf::Keyboard::Divide, "divide"},
        {sf::Keyboard::Left, "left-arrow"},
        {sf::Keyboard::Right, "right-arrow"},
        {sf::Keyboard::Up, "up-arrow"},
        {sf::Keyboard::Down, "down-arrow"},
        {sf::Keyboard::Numpad0, "numpad-0"},
        {sf::Keyboard::Numpad1, "numpad-1"},
        {sf::Keyboard::Numpad2, "numpad-2"},
        {sf::Keyboard::Numpad3, "numpad-3"},
        {sf::Keyboard::Numpad4, "numpad-4"},
        {sf::Keyboard::Numpad5, "numpad-5"},
        {sf::Keyboard::Numpad6, "numpad-6"},
        {sf::Keyboard::Numpad7, "numpad-7"},
        {sf::Keyboard::Numpad8, "numpad-8"},
        {sf::Keyboard::Numpad9, "numpad-9"},
        {sf::Keyboard::F1, "f1"},
        {sf::Keyboard::F2, "f2"},
        {sf::Keyboard::F3, "f3"},
        {sf::Keyboard::F4, "f4"},
        {sf::Keyboard::F5, "f5"},
        {sf::Keyboard::F6, "f6"},
        {sf::Keyboard::F7, "f7"},
        {sf::Keyboard::F8, "f8"},
        {sf::Keyboard::F9, "f9"},
        {sf::Keyboard::F10, "f10"},
        {sf::Keyboard::F11, "f11"},
        {sf::Keyboard::F12, "f12"},
        {sf::Keyboard::Pause, "pause"}
    };

    auto keyStr = keyMap.find(key);
    if (keyStr != keyMap.end()) {
        return keyStr->second;
    } else {
        return "unknown-key";
    }
}

void Graphics::catchEvents() {
    sf::Event event = sf::Event();

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            close();
        }
        if (event.type == sf::Event::KeyPressed) {
            bool alreadyPressed = false;
            for (auto key: keysPressed) {
                if (key == event.key.code) {
                    alreadyPressed = true;
                    break;
                }
            }
            if (alreadyPressed) {
                continue;
            }
            const std::string keyName = keyToString(event.key.code);
            EventSystem::getInstance().triggerEvents(keyName + "_pressed", nullptr);
            keysPressed.push_back(event.key.code);
        }
        if (event.type == sf::Event::KeyReleased) {
            const std::string keyName = keyToString(event.key.code);
            EventSystem::getInstance().triggerEvents(keyName + "_released", nullptr);
            for (auto key = keysPressed.begin(); key != keysPressed.end(); ++key) {
                if (*key == event.key.code) {
                    keysPressed.erase(key);
                    break;
                }
            }
        }
    }
}

void Graphics::render(const std::function<void(IObject *)> &updateFunction) {
    if (!prepared) {
        return;
    }
    if (currentScene == nullptr) {
        currentScene = SceneManager::getInstance().getCurrentScene();
    }
    clear();

    catchEvents();
    const std::vector<IObject *> objects = currentScene->getObjects();
    for (auto *object: objects) {
        addAndSortObject(object);
    }
    std::sort(sortedObjects.begin(), sortedObjects.end(),
              [](IObject *obja, IObject *objb) {
                  auto *aTransform = getObjComponent<Transform>(obja);
                  auto *bTransform = getObjComponent<Transform>(objb);
                  if (aTransform == nullptr || bTransform == nullptr) {
                      return false;
                  }
                  return aTransform->getPosition().z < bTransform->getPosition().z;
              });
    for (auto *object: sortedObjects) {
        if (!object->isActive()) {
            continue;
        }
        for (auto *const component: object->getComponents()) {
            component->beforeRendering();
        }
    }
    for (auto *object: sortedObjects) {
        if (!object->isActive()) {
            continue;
        }
        updateFunction(object);
        for (auto *const component: object->getComponents()) {
            if (auto *graphicsComponent = dynamic_cast<IGraphicsComponent *>(component)) {
                graphicsComponent->render(&window);
            }
        }
    }
    for (auto *object: sortedObjects) {
        if (!object->isActive()) {
            continue;
        }
        for (auto *const component: object->getComponents()) {
            component->afterRendering();
        }
    }

    present();
}

void Graphics::close() {
    EventSystem::getInstance().triggerEvents("window_closed", nullptr);
    window.close();
    prepared = false;
}

void Graphics::setScene(IScene *scene) {
    currentScene = scene;
    sortedObjects.clear();
}
