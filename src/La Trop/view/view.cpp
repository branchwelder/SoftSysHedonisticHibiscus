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
    
    for (auto it : _model->getWorld()) {
        _renderBlock(it.first, it.second);
    }
    _renderPortal();
    _renderPlayer();
    glutSwapBuffers();
}

void View::_renderBlock(Vector position, Block block) {
    SquareView square(position.first, position.second, block.getColor());
    square.render();
}

void View::_renderPlayer() {
    Vector position = _model->getPlayer().getPosition();
    Color playerColor = (Color) { 0.75, 0.75, 0.75 };
    SquareView square(position.first, position.second, playerColor);
    square.render();
}

void View::_renderPortal() {
    for (int i = 0; i < 2; i++) {
        PortalEntrance entrance = _model->getPortal().getEntrance(i);
        Vector position = entrance.position;
        SquareView square(position.first, position.second, entrance.color);
        square.render();
    }
}
