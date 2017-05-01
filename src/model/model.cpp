//
//  model.cpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <GLUT/glut.h>
#include "model.hpp"
#include "types.h"

BlockMap Model::getWorld() {
    return _world;
}

Player& Model::getPlayer() {
    return _player;
}

void Model::addBlock(float x, float y, Block block) {
    _world.insert(std::make_pair(std::make_pair(x, y), block));
}

int Model::_checkCollision(Position corner1, Position corner2) {
    float d1x = corner2.first - (corner1.first + 1);
    float d1y = corner2.second - (corner1.second + 1);
    float d2x = corner1.first - (corner2.first + 1);
    float d2y = corner1.second - (corner2.second + 1);
    
    if (d1x > 0.0f || d1y > 0.0f) {
        return 0;
    }
    if (d2x > 0.0f || d2y > 0.0f) {
        return 0;
    }

    float xDiff = std::abs(corner1.first - corner2.first);
    float yDiff = std::abs(corner1.second - corner2.second);
    if (xDiff > yDiff) {
        return 1;
    } else {
        return 2;
    }
}

float Model::_handleCollision(float moving, float stationary) {
    float diff = stationary - moving + (moving > stationary ? 1 : -1);
    return diff;
}

void Model::_movePlayer(float dx, float dy) {
    _player.move(dx, dy);
}

void Model::updateKeyState(unsigned char key, bool val) {
    _keyStates[key] = val;
}

void Model::_processKeys() {
    if (_keyStates['a'] && !_keyStates['d']) {
        _player.setActiveVelocity(-PLAYER_SPEED, 0.0f);
    } else if (_keyStates['d'] && !_keyStates['a']) {
        _player.setActiveVelocity(PLAYER_SPEED, 0.0f);
    } else {
        _player.setActiveVelocity(0.0f, 0.0f);
    }
}

void Model::_handlePhysics(float dt) {
    float dydt = GRAVITY * (dt / 1000.0f);
    double dx = _player.getVelocity().first * (dt / 1000.0f);
    double dy = (_player.getVelocity().second + dydt) * (dt / 1000.0f);
    Position newPosition = Position(
        _player.getPosition().first + dx,
        _player.getPosition().second + dy
    );

    bool xCollision = false;
    bool yCollision = false;
    for (auto it : _world) {
        int collision = _checkCollision(it.first, newPosition);
        if (collision == 1 && !xCollision) {
            xCollision = true;
            dx += _handleCollision(newPosition.first, it.first.first);
        }
        if (collision == 2 && !yCollision) {
            yCollision = true;
            dy += _handleCollision(newPosition.second, it.first.second);
        }
        if (xCollision && yCollision) {
            break;
        }
    }

    if (yCollision) {
        if (!_player.onGround) {
            _player.onGround = true;
            _player.resetPassiveVelocity();
        }
    } else {
        if (_player.onGround) {
            _player.onGround = false;
        }
        _player.changePassiveVelocity(0.0f, dydt);
    }

    _movePlayer(dx, dy);
}

void Model::update() {
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    int dt = currentTime - _time;
    _processKeys();
    _handlePhysics(dt);
    _time = currentTime;
}
