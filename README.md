# R-Type: Reborn

![R-Type: Reborn](https://i.ibb.co/yRX833y/H2x1-Wii-UVC-RType.jpg)

![EPITECH Project](https://img.shields.io/badge/EPITECH-2024-007EC6?style=for-the-badge&logo=epitech&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-184F9C?style=for-the-badge&logo=SFML&logoColor=green)
![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Fedora](https://img.shields.io/badge/Fedora-294172?style=for-the-badge&logo=fedora&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

**R-Type: Reborn** is a modern reimagining of the classic arcade shoot 'em up, combining nostalgic gameplay with new features and enhancements.

This project is divided into two key components:
- [**Stellar Forge**](https://github.com/epitech-mirroring/Stellar-Forge) : The game engine powering R-Type: Reborn.
- [**Orion Editor**](https://github.com/epitech-mirroring/Orion-Editor): The game editor used to create and modify game levels and assets.

## Table of Contents

- [Project Purpose](#project-purpose)
- [Dependencies & Requirements](#dependencies--requirements)
- [Supported Platforms](#supported-platforms)
- [Build Instructions](#build-instructions)
- [Documentation](#documentation)
- [Authors & Contact](#authors--contact)
- [Useful Links](#useful-links)
- [Quick Start](#quick-start)

## Project Purpose

Welcome to **R-Type: Reborn**, a project developed as part of the Advanced C++ knowledge unit at EPITECH. This initiative introduces networked video game development while pushing the boundaries of advanced programming techniques and promoting best practices in software engineering.

Our goal is to create a multithreaded server and a graphical client for the iconic **R-Type** game, using a game engine designed entirely by us.

Through **R-Type: Reborn**, we aim to offer a modern take on a classic game while applying cutting-edge C++ techniques in a networked gaming environment.

The purpose of **R-Type: Reborn** is also to modernize the classic R-Type experience, bringing new graphics, levels, and game mechanics while maintaining the core gameplay that made the original famous. This project also serves as a demonstration of the **Stellar Forge** engine and **Orion Editor**.


## Dependencies & Requirements

To build and run the project, you will need:

- **C++** compiler supporting C++17 or later
- **SFML** (Simple and Fast Multimedia Library) for graphics, audio and input handling
- **CMake** for building the project
- **GLM** (OpenGL Mathematics) for vector and matrix operations
- **Conan** for managing dependencies

Install the dependencies using the package manager for your platform, or refer to the official documentation for each tool.

## Supported Platforms

- Windows 10+
- Linux (Fedora, Ubuntu, etc.)

## Build Instructions

To build **R-Type: Reborn**, follow these steps:

*Note: These instructions are used to recompile the project from source. If you just want to run the game without compiling it see the [Quick Start](#quick-start) section.*

### Windows

1. Clone the repository to your local machine.
2. Open a terminal and navigate to the project directory.
3. Launch the following commands:
```bash
./build-windows.ps1
```
4. Accept the installation of the dependencies.
5. You can run the project by launching the executable in the `build` directory or by running the `r-type_client` and `r-type_server` executables at the root of the project.

### Linux

1. Clone the repository to your local machine.
2. Open a terminal and navigate to the project directory.
3. Launch the following commands: (You need to have sudo rights)
```bash
sudo ./build-linux.sh
```
4. Accept the installation of the dependencies.
5. You can run the project by launching the executable in the `build` directory or by running the `r-type_client` and `r-type_server` executables at the root of the project.


## Documentation

You can find the documentation for **Stellar Forge** in
the [R-Type: Reborn](https://github.com/epitech-mirroring/R-Type-Reborn) repository or in
the [Documentation](https://github.com/epitech-mirroring/R-Type-docs) repository.
You can also find the documentation on the following
website: [Stellar Forge Documentation](https://wiki.simon-gl.fr/en/home).
If you have any questions or need help, feel free to reach out to the authors.
## Authors & Contact

<table>
    <tbody>
        <tr>
            <td align="center"><a href="https://github.com/Marius-P1/"><img src="https://avatars.githubusercontent.com/u/114705049?&=4" width="100px;" alt="Marius-P1"/><br/><sub><b>Marius PAIN</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/AubaneNourry/"><img src="https://avatars.githubusercontent.com/u/114694895?v=4" width="100px;" alt="AubaneNourry"/><br/><sub><b>Aubane NOURRY</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/6im0n/"><img src="https://avatars.githubusercontent.com/u/46846093?v=4" width="100px;" alt="6im0n"/><br/><sub><b>Simon GANIER-LOMBARD</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/RenardFute/"><img src="https://avatars.githubusercontent.com/u/38489683?v=4" width="100px;" alt="RenardFute"/><br/><sub><b>Axel ECKENBERG</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/landryarki/"><img src="https://avatars.githubusercontent.com/u/114699649?v=4" width="100px;" alt="landryarki"/><br/><sub><b>Landry GIGANT</b></sub></a><br/></td>
        </tr>
    </tbody>
</table>

## Useful Links

- [EPITECH](https://www.epitech.eu/)
- [Stellar Forge](https://github.com/epitech-mirroring/Stellar-Forge)
- [Orion Editor](https://github.com/epitech-mirroring/Orion-Editor)
- [R-Type: Reborn](https://github.com/epitech-mirroring/R-Type-Reborn)
- [R-Type: Reborn Wiki](https://wiki.simon-gl.fr)

## Quick Start

### Windows

1. Download the release package from the [Releases](https://github.com/epitech-mirroring/R-Type-Reborn/releases) page.
2. Launch the `r-type-"release_version"-win64.exe` file.
3. Follow the on-screen instructions to install the game.
4. Once installed, you can start the game by double-clicking the `r-type_client.exe` or `r-type_server.exe` files on your desktop.

### Linux (Fedora)

1. Download the release package from the [Releases](https://github.com/epitech-mirroring/R-Type-Reborn/releases) page.
2. Launch the 'r-type-reborn.rpm' file.
3. Follow the on-screen instructions to install the game.
4. Once installed, you can start the game by launching the `r-type_client` or `r-type_server` executables in the folder where the game was installed.
*The installation path is usually `/usr/local/bin/`.*
5. The server need the following arguments to run:
```bash
r-type_server <port_TCP> <port_UDP>
```
6. The client does not need any arguments to run.
