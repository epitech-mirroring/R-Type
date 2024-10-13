# Stellar Forge : Game Engine

## Introduction

Welcome to the developers documentation for **Stellar Forge**!
This document is intended for developers who wish to contribute to the project or learn more about the technologies used in the game engine.

## Table of Contents

- [Architecture](#architecture)
- [Components](#components)
- [Event System](#event-system)
- [Configuration](#configuration)
- [How to make changes](#how-to-make-changes)
  - [Adding new components](#adding-new-components)

## Architecture

**Stellar Forge** is a modern game engine designed to power the **R-Type: Reborn** project.
The engine is built using C++17 and leverages the SFML (Simple and Fast Multimedia Library) for graphics, audio, and input handling.

The engine is divided into several components, each responsible for a specific aspect of the game:

- **Graphic Engine**: Responsible for rendering the objects that make up the game world.
- **Config Reader**: Reads and parses configuration files to load game assets and settings.
- **Event System**: Listens for and dispatches events to the appropriate game objects.
- **Scene Manager**: Manages the game scenes, including loading, unloading, and transitioning between scenes.
- **Object Manager**: Manages the game objects, including creating, updating, and destroying objects.
- **Objects**: The game objects that make up the game world, including entities, components, and scenes.
  - **Components**: The building blocks of game objects, defining their behavior, appearance, and interactions.


Here is an overview of the Stellar Forge architecture (Yes, it's complicated):
```mermaid
flowchart LR
 
    scene_manager[scene manager]
    event_sys[event system]
    object_management[object manager]
    config_reader[config reader]
    factory[factory]
    subgraph Game_engine
        scene_manager -- Contain[1] --> object_management 
        object_management <--> event_sys 
        object_management --Contain[?]--> factory 
        subgraph Bootstrap
            config_reader
        end
        Bootstrap --Initialize--> object_management
        Bootstrap --Feed--> factory
        Bootstrap --Initialize--> event_sys
        Bootstrap --Initialize--> scene_manager
    end
 
    scene[scene]
    object[object]
    components[components]
    sprites[sprites]
 
    UI_text[UI text]
    UI_buttons[UI buttons]
    CppMonoBehaviours[CppMonoBehaviours]
    rigid_body[rigid body]
    scripts[scripts]
    animated_sprites[animated sprites]
 
 
    Game_engine --Contain[?]--> scene 
    scene --Contain[N]--> object
    object --Contain[N]--> components
    components -.-> sprites
    subgraph Components
        sprites -.-> animated_sprites
        components -.-> UI_text
        components -.-> UI_buttons
        components -.-> CppMonoBehaviours
        components -.-> scripts
        components -.-> rigid_body
    end
    scripts --Can access--> Game_engine
    CppMonoBehaviours --Can access--> Game_engine
```
    
## Components

Each object in the game world is composed of several components that define its behavior, appearance, and interactions.
Here are some of the key components used in **Stellar Forge**:

- **Transform**: Defines the position, rotation, and scale of an object.
- **Sprite**: Renders a 2D image on the screen.
- **Animated Sprite**: Renders a sequence of images to create an animation.
- **Rigid Body**: Simulates physics interactions between objects.
- **UI Text**: Displays text on the screen.
- **UI Button**: Represents an interactive button on the screen.
- **CppMonoBehaviours**: Allows developers to attach C++ scripts to game objects.

(All these components are already implemented in the engine, and you can use them to create your game objects.)

### CppMonoBehaviours

The `CppMonoBehaviours` component allows developers to attach C++ scripts to game objects.
These scripts can be used to define custom behavior, interactions, and game logic for the objects.
To write a C++ script, you need to inherit from the `CppMonoBehaviour` class and implement the `update` method.
You can also use the `start`, `end`, `before` and `after` methods to perform initialization and cleanup tasks.


## Event System

The event system in **Stellar Forge** is responsible for listening for and dispatching events to the appropriate game objects.
Events are used to communicate between different parts of the game, such as input handling, collision detection, and object interactions.
You can register event listeners in your game objects to respond to specific events, such as key presses, mouse clicks, or collisions.

By default, the graphic engine triggers all events linked to the window (like key press, etc).
*(if the user press the `Z` key, the engine will trigger an event with the name `z_pressed`)*
You can also trigger custom events in your game objects to communicate between them.

For example, you can listen for the `Z` key press event and move the player object when the key is pressed.
To do this, you need to register an event with the name `z_pressed` and a callback function that moves the player object.


## Configuration

**Stellar Forge** uses configuration files to load you game objects, scenes, and settings.
The configuration files are written in JSON format and are located in the `assets` directory.

Here is an example of a configuration file for a game object:
```json
{
  "id": "9f19e43c-990b-4314-a039-d729a1dab876",
  "meta": {
    "name": "Ally"
  },
  "isActive": false,
  "child": [],
  "components": [
    {
      "name": "Transform",
      "data": {
        "position": {
          "x": 0,
          "y": 0,
          "z": 0
        },
        "rotation": {
          "x": 0,
          "y": 0,
          "z": 0
        },
        "scale": {
          "x": 1,
          "y": 1,
          "z": 1
        }
      }
    },
    {
      "name": "Sprite",
      "data": "client/objects/assets/ally.png"
    }
  ]
}
```
The configuration file contains the following fields:
- **id**: A unique identifier for the object (UUID).
- **meta**: Additional metadata about the object, such as its name.
- **isActive**: Whether the object is active or not.
- **child**: An array of child objects.
- **components**: An array of components that define the object's behavior and appearance.

Each component has a name and data field that contains the component-specific settings.

Here is an example of a configuration file for a scene:
```json
{
  "id": "4548bf85-6bb2-4ba7-88bf-856bb22ba7d1",
  "objects": [
    "9f19e43c-990b-4314-a039-d729a1dab876"
  ]
}
```

The scene configuration file contains the following fields:
- **id**: A unique identifier for the scene (UUID).
- **objects**: An array of object IDs that belong to the scene.

## How to make changes

If you want to contribute to **Stellar Forge** or make changes to the engine, here are some guidelines to follow:

### Adding new components

To add a new component to the engine, follow these steps:

1. Create a new class that inherits from the `IComponent` interface or one of its subclasses (e.g., `AComponent`).
   *(If you want to create a new graphic component, you have to also inherit from the `IGraphicComponent` interface)*
2. Implement the required methods for the component, such as `update`, `clone`, `deserialize` and `serializeData`.
*(If you don't use the abstract class `AComponent`, you will have to implement all the methods of the `IComponent` interface)*
3. Register the new component in the `ComponentFactory` class so that it can be created dynamically.
4. Use the new component in your game objects by adding it to the object's configuration file.

Now you can use your new component in the engine to create custom game objects with unique behavior and appearance.

You can propose your changes to the project maintainers for review and integration into the main codebase.
