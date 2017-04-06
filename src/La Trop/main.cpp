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
int WINDOW_WIDTH = 640;
int WINDOW_HEIGHT = 480;
int WINDOW_POS_X = 50;
int WINDOW_POS_Y = 50;

// scale factor from world coordinates to pixels
float SCALE = 10.0;

// initial ranges of world coordinates
float INITIAL_X_MIN = -(WINDOW_WIDTH / 2.0) / SCALE;
float INITIAL_X_MAX = (WINDOW_WIDTH / 2.0) / SCALE;
float INITIAL_Y_MIN = -(WINDOW_HEIGHT / 2.0) / SCALE;
float INITIAL_Y_MAX = (WINDOW_HEIGHT / 2.0) / SCALE;

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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
    glutCreateWindow("La Trop");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(INITIAL_X_MIN, INITIAL_X_MAX, INITIAL_Y_MIN, INITIAL_Y_MAX);
}

void idleFunc() {
    glutPostRedisplay();
}

void display() {
    view->render();
}

void keyboard(unsigned char key, int x, int y) {
    controller->handleKeyboard(key, x, y);
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

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glutIdleFunc(idleFunc);

    model = new Model();
    view = new View(model);
    controller = new Controller(model);

    model->addBlock(5, 5, Block(RED));
    model->addBlock(12, 20, Block(SILVER));
    
    // Initialize player that can be moved by the keyboard
    model->initPlayer(15,15, Player(15,15,100));

    glutMainLoop();

    return 0;
}
