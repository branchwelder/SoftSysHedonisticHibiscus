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
            std::cout << "fire left portal";
            break;
        case 'e':
            std::cout << "fire right portal";
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

}
