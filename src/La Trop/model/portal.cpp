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
        Vector(-10.0f, -18.0f),
        -1,
        (Color) { 0.5, 0.15, 0.7 }
    };
    _entrances.first = entrance;
    entrance.color = (Color) { 0.3, 0.8, 0.15 };
    entrance.position = Vector(15.0f, 20.0f);
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

void Portal::moveEntrance(int num, Vector position, int side) {
    if (num != 0 && num != 1) return;
    PortalEntrance& entrance = getEntrance(num);
    entrance.active = true;
    entrance.position = position;
    entrance.side = side;
}

Vector Portal::getTeleportDistance() {
    return Vector(
        _entrances.first.position.first - _entrances.second.position.first,
        _entrances.first.position.second - _entrances.second.position.second
    );
}
