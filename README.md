# Lá Trop
## Hedonistic Hibiscus: Software Systems 2017

## Game development in C++ using GLUT and OpenGL.

A game implementation in C++ using OpenGL to render sprites and graphics. The game consists of player movement from a two-dimensional, side view perspective. Player movement is controlled by WASD or the arrow keys, as well as physics-like forces (gravity) causing the player to fall. Solve interesting levels using portals (with Q and A keys) to teleport around the map and complete a level.

[Check out our final report website](https://hannahtwiggsmith.github.io/SoftSysHedonisticHibiscus/)

## Authors
[Hannah Twigg-Smith](https://github.com/hannahtwiggsmith), [Philip Seger](https://github.com/segerphilip), [Sam Myers](https://github.com/sammyers)

## Getting Started

This project was developed in Xcode, so if you are running on a Mac then download Xcode, clone this repo, open the project with `open src/La\ Trop.xcodeproj/`, and click run (or CMD+r).

If you are not running on a Mac, there is a way to compile this project in other OSes, however the previous tools to do so were deprecated (specifically pbxbuild).

## Usage
WASD or up, left, down, right: character movement.

Q: fire the purple portal.

E: fire the green portal.

Esc: exit the game.

If you want to use/load a level, they are saved in .txt files and should be placed in the src/ root. They are passed into the program as a second argument when running from terminal, e.g. `./`

## License
[MIT License](https://github.com/hannahtwiggsmith/SoftSysHedonisticHibiscus/blob/master/LICENSE)
