# Lá Trop
## Hedonistic Hibiscus: Software Systems 2017

## Game development in C++ with GLUT and OpenGL.

Là Trop is a two-dimensional, Portal-inspired platformer created in C++ and OpenGL. The player can place two portals which teleport them to the other location on contact. The game world is viewed from the side, and the player is affected by gravity, obstacles, and enemies. They must teleport around to complete levels.

[Check out our final report website](https://hannahtwiggsmith.github.io/SoftSysHedonisticHibiscus/)

## Authors
[Hannah Twigg-Smith](https://github.com/hannahtwiggsmith), [Philip Seger](https://github.com/segerphilip), and [Sam Myers](https://github.com/sammyers)

## Getting Started

For Mac users, this project is easily run with XCode:
1. Clone this repo and move into the top-level directory
2. Open the project with `open src/La\ Trop.xcodeproj/`
3. Click run (or CMD+r).

If you are not running on a Mac, there is a way to compile this project in other OSes, however the previous tools to do so were deprecated (specifically pbxbuild).

## Usage
A&D: Left and right movement

W: Jump

Q: fire the purple portal

E: fire the green portal

Esc: exit the game

If you want to use/load a level, they are saved in .txt files and should be placed in the src/ root. They are passed into the program as a second argument when running from terminal, e.g. `./`

## License
[MIT License](https://github.com/hannahtwiggsmith/SoftSysHedonisticHibiscus/blob/master/LICENSE)
