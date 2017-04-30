//
//  player.cpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include "player.hpp"

Position Player::getPosition() {
    return _position;
}

Velocity Player::getVelocity() {
    return Velocity(_dxdt, _dydt);
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

void Player::setVelocity(float dxdt, float dydt) {
    _dxdt = dxdt;
    _dydt = dydt;
}
