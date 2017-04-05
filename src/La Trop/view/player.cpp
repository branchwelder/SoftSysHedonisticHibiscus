//
//  player.cpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "player.hpp"
#include "../model/player.hpp"

PlayerView::PlayerView(float x, float y) : _x(x), _y(y) {}

void PlayerView::render() {

    // TODO: Replace this with a texture.
    glColor3f(0.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
    glVertex2f(_x, _y);
    glVertex2f(_x + 1, _y);
    glVertex2f(_x + 1, _y + 1);
    glVertex2f(_x, _y + 1);
    glEnd();
    
    glutSwapBuffers();
}
