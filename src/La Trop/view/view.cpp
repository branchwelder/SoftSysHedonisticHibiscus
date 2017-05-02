//
//  view.cpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "view.hpp"
#include "square.hpp"
#include <SOIL/SOIL.h>

void View::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    _renderPortalTarget();

    for (auto it : _model->getWorld()) {
        _renderBlock(it.first, it.second);
    }
    _renderPortal();
    _renderPlayer();
    glutSwapBuffers();
}

void View::_renderBlock(Vector position, Block block) {
    SquareView square(position, block.getColor());
    square.render();
}

void View::_renderPlayer() {
    Vector position = _model->getPlayer().getPosition();
    Color playerColor = (Color) { 0.2, 0.6, 1.0 };
    SquareView square(position, playerColor);
    square.render();
}

void View::_renderPortal() {
    for (int i = 0; i < 2; i++) {
        PortalEntrance entrance = _model->getPortal().getEntrance(i);
        if (entrance.active) {
            SquareView square(entrance.position, entrance.color);
            square.render();
        }
    }
}

void View::_renderPortalTarget() {
    Color targetColor = (Color) { 0.4, 0.4, 0.4 };
    Color auxColor = (Color) { 0.1, 0.1, 0.1 };
    Vector target = _model->getPortalTarget();
    SquareView square(target, targetColor);
    square.render();
    for (int i = -1; i <= 1; i+=2) {
        square = SquareView(Vector(target.first + i, target.second), auxColor);
        square.render();
        square = SquareView(Vector(target.first, target.second + i), auxColor);
        square.render();
    }
}
