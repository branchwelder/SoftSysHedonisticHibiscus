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

void Controller::handleKeyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 27:
            exit(0);
        case 'w':
            _model->movePlayer(0,1);
            break;
        case 'a':
            _model->movePlayer(-1,0);
            break;
        case 's':
            _model->movePlayer(0,-1);
            break;
        case 'd':
            _model->movePlayer(1,0);
            break;
        case 'q':
            std::cout << "fire left portal";
            break;
        case 'e':
            std::cout << "fire right portal";
            break;
    }
    _view->render();
}

void Controller::handleSpecialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP:
            _model->movePlayer(0,1);
            break;
        case GLUT_KEY_LEFT:
            _model->movePlayer(-1,0);
            break;
        case GLUT_KEY_DOWN:
            _model->movePlayer(0,-1);
            break;
        case GLUT_KEY_RIGHT:
            _model->movePlayer(1,0);
            break;
    }
    _view->render();
}
