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
#include "view/square.hpp"
#include "view/player.hpp"
#include "view/view.hpp"
#include "model/model.hpp"
#include "controller/controller.hpp"

// initial window attributes
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_POS_X 50
#define WINDOW_POS_Y 50

// scale factor from world coordinates to pixels
#define SCALE 10.0

// initial ranges of world coordinates
#define INITIAL_X_MIN -(WINDOW_WIDTH / 2.0) / SCALE
#define INITIAL_X_MAX (WINDOW_WIDTH / 2.0) / SCALE
#define INITIAL_Y_MIN -(WINDOW_HEIGHT / 2.0) / SCALE
#define INITIAL_Y_MAX (WINDOW_HEIGHT / 2.0) / SCALE

// some colors
Color WHITE = (Color) { 1.0, 1.0, 1.0 };
Color SILVER = (Color) { 0.75, 0.75, 0.75 };
Color RED = (Color) { 1.0, 0.0, 0.0 };
Color GREEN = (Color) { 0.0, 1.0, 0.0 };
Color BLUE = (Color) { 0.0, 0.0, 1.0 };

Model *model;
View *view;
Controller *controller;


void initialize() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
    glutCreateWindow("Là Trop");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(INITIAL_X_MIN, INITIAL_X_MAX, INITIAL_Y_MIN, INITIAL_Y_MAX);
}

void idleFunc() {
    glutPostRedisplay();
}

void display() {
    model->update();
    view->render();
}

void keyboard(unsigned char key, int x, int y) {
    controller->handleKeyPress(key, x, y);
}

void keyboardUp(unsigned char key, int x, int y) {
    controller->handleKeyRelease(key, x, y);
}

void specialKeys(int key, int x, int y) {
    controller->handleSpecialKeys(key, x, y);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // set clipping area so the world stays centered
    GLfloat xClipLeft = -(width / 2.0) / SCALE;
    GLfloat xClipRight = (width / 2.0) / SCALE;
    GLfloat yClipBottom = -(height / 2.0) / SCALE;
    GLfloat yClipTop = (height / 2.0) / SCALE;
    
    gluOrtho2D(xClipLeft, xClipRight, yClipBottom, yClipTop);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    initialize();
    
    model = new Model();
    view = new View(model);
    controller = new Controller(model);
    
    if ( argc == 2 ) {
        // TODO check input for levels existing/properly formatted
        model->readLevel(argv[1]);
    } else {
        model->addBlock(5, -2, Block(RED));
        for (int i = -32; i < 32; i++) {
            model->addBlock(i, 23, Block(SILVER));
            model->addBlock(i, -24, Block(SILVER));
        }
        for (int i = -23; i < 23; i++) {
            model->addBlock(-32, i, Block(SILVER));
            model->addBlock(31, i, Block(SILVER));
        }
    }

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glutIdleFunc(idleFunc);
    
    glutMainLoop();

    return 0;
}
