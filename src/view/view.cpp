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
    
    Position playerPosition = _model->getPlayer().getPosition();
    _renderPlayer(playerPosition);
    glutSwapBuffers();
}

void View::_renderBlock(Position position, Block block) {
    Square square(position.first, position.second, block.getColor());
    square.render();
}

void View::_renderPlayer(Position position) {
    Color playerColor = (Color) { 0.75, 0.75, 0.75 };
    Square square(position.first, position.second, playerColor);
    square.render();
}
