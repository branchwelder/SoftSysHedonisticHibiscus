//
//  player.cpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include "player.hpp"

Vector Player::getPosition() {
    return _position;
}

Velocity Player::getVelocity() {
    return Velocity(
        _activeVelocity.first + _passiveVelocity.first,
        _activeVelocity.second + _passiveVelocity.second
    );
}

bool Player::getGun() {
    return _gun; // Should player start with gun?
}

void Player::setGun(bool status) {
    _gun = status;
}

void Player::move(float dx, float dy) {
    _position.first += dx;
    _position.second += dy;
}

void Player::jump() {
    if (onGround) {
        _passiveVelocity.second += JUMP_VELOCITY;
        onGround = false;
    }
}

void Player::setActiveVelocity(float dxdt, float dydt) {
    _activeVelocity.first = dxdt;
    _activeVelocity.second = dydt;
}

void Player::changePassiveVelocity(float dxdt, float dydt) {
    _passiveVelocity.first += dxdt;
    _passiveVelocity.second += dydt;
}

void Player::resetPassiveVelocity() {
    _passiveVelocity.first = 0.0f;
    _passiveVelocity.second = 0.0f;
}
