//
//  square.cpp
//  La Trop
//
//  Created by Sam Myers on 4/1/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "square.hpp"
#include "../model/block.hpp"

Square::Square(float x, float y, Color color) : _x(x), _y(y), _color(color) {}

void Square::render() {
    glColor3f(_color.red, _color.green, _color.blue);

    glBegin(GL_POLYGON);
    glVertex2f(_x, _y);
    glVertex2f(_x + 1, _y);
    glVertex2f(_x + 1, _y + 1);
    glVertex2f(_x, _y + 1);
    glEnd();
}
