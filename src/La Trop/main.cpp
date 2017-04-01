//
//  main.cpp
//  La Trop
//
//  Created by Sam Myers on 3/30/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("square");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
