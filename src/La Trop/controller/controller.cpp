//
//  controller.cpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include "controller.hpp"

void Controller::handleKeyPress(unsigned char key, int x, int y) {
    switch(key) {
        case 27:
            exit(0);
        case 'q':
            _model->movePortalEntrance(0);
            break;
        case 'e':
            _model->movePortalEntrance(1);
            break;
        case 'w':
            _model->getPlayer().jump();
        default:
            _model->updateKeyState(key, true);
    }
}

void Controller::handleKeyRelease(unsigned char key, int x, int y) {
    _model->updateKeyState(key, false);
}

void Controller::handleSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            _model->movePortalTarget(0.0f, 1.0f);
            break;
        case GLUT_KEY_DOWN:
            _model->movePortalTarget(0.0f, -1.0f);
            break;
        case GLUT_KEY_LEFT:
            _model->movePortalTarget(-1.0f, 0.0f);
            break;
        case GLUT_KEY_RIGHT:
            _model->movePortalTarget(1.0f, 0.0f);
            break;
        default:
            break;
    }
}
