//
//  model.cpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include "model.hpp"
#include "types.h"

BlockMap Model::getWorld() {
    return _world;
}

Player Model::getPlayer() {
    return _player;
}

void Model::addBlock(float x, float y, Block block) {
    _world.insert(std::make_pair(std::make_pair(x, y), block));
}

int Model::checkBlock(float dx, float dy) {
    // x and y are delta in position, so we need the players
    // actual position plus the change to compare with blocks
    float newX = _player.getPosition().first + dx;
    float newY = _player.getPosition().second + dy;
    
    int exists = _world.count(std::make_pair(newX, newY));
    if (exists) {
        return 1;
    }
    return 0;
}

void Model::_movePlayer(float dx, float dy) {
    // check to not overlap a block
    if (checkBlock(dx, dy) == 0) {
        _player.move(dx, dy);
    }
}

void Model::updateKeyState(unsigned char key, bool val) {
    _keyStates[key] = val;
}

void Model::_processKeys() {
    if (_keyStates['a'] && !_keyStates['d']) {
        _player.setVelocity(-PLAYER_SPEED, 0);
    } else if (_keyStates['d'] && !_keyStates['a']) {
        _player.setVelocity(PLAYER_SPEED, 0);
    } else {
        _player.setVelocity(0, 0);
    }
}

void Model::update() {
    fprintf(stderr, "%d %d\n", _keyStates['a'], _keyStates['d']);
    _processKeys();
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    int dt = currentTime - _time;
    double dx = _player.getVelocity().first * (dt / 1000.0);
    double dy = _player.getVelocity().second * ( dt / 1000.0);
    fprintf(stderr, "%f %f\n", dx, dy);
    _movePlayer(dx, dy);
    _time = currentTime;
}
