//
//  main.cpp
//  La Trop
//
//  Created on 3/30/17.
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

void keyboardControl(unsigned char key, int x, int y) {
    switch(key) {
        case 27:
            exit(0);
        case 'w':
            std::cout << "up";
            break;
        case 'a':
            std::cout << "left";
            break;
        case 's':
            std::cout << "down";
            break;
        case 'd':
            std::cout << "right";
            break;
        case 'q':
            std::cout << "fire left portal";
            break;
        case 'e':
            std::cout << "fire right portal";
            break;
    }
}

void specialKeyControl(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP:
            std::cout << "up";
            break;
        case GLUT_KEY_LEFT:
            std::cout << "left";
            break;
        case GLUT_KEY_DOWN:
            std::cout << "down";
            break;
        case GLUT_KEY_RIGHT:
            std::cout << "right";
            break;
    }
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
    glutKeyboardFunc(keyboardControl);
    glutSpecialFunc(specialKeyControl);
    glutMainLoop();
    return 0;
}
