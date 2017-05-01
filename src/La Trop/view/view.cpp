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
        int x = it.first.first;
        int y = it.first.second;
        Color color = it.second.getColor();

        SquareView square(x, y, color);
        square.render();
    }
    
    playerPosition player = _model->getPlayer();
    int x = player.first.first;
    int y = player.first.second;
    PlayerView p1(x, y);
    p1.render();
    glutSwapBuffers();
}
