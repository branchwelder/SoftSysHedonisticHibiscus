//
//  player.cpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include "player.hpp"

bool Player::getGun() {
    return _gun; // Should player start with gun?
}

void Player::setGun(bool status) {
    _gun = status;
}
