//
//  portal.cpp
//  La Trop
//
//  Created by Sam Myers on 5/1/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include "portal.hpp"

Portal::Portal() {
    PortalEntrance entrance = (PortalEntrance) {
        false,
        Position(0.0f, 0.0f),
        -1,
        (Color) { 0.5, 0.15, 0.7 }
    };
    _entrances.first = entrance;
    entrance.color = (Color) { 0.3, 0.8, 0.15 };
    entrance.blockPosition = Position(5.0f, 0.0f);
    _entrances.second = entrance;
}

bool Portal::isActive() {
    return _entrances.first.active && _entrances.second.active;
}

PortalEntrance& Portal::getEntrance(int num) {
    if (num != 0 && num != 1) {
        throw std::invalid_argument("invalid entrance number");
    }
    return (num == 0) ? _entrances.first : _entrances.second;
}

void Portal::moveEntrance(int num, Position position, int side) {
    if (num != 0 && num != 1) return;
    PortalEntrance& entrance = getEntrance(num);
    entrance.active = true;
    entrance.blockPosition = position;
    entrance.side = side;
}
