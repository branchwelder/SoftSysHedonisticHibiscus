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

void Controller::handleSpecialKeys(int key, int x, int y) {
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
