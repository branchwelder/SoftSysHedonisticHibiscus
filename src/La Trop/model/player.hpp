//
//  player.hpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef player_model_hpp
#define player_model_hpp

#include "types.h"

class Player {
public:
    Player(float x = 15, float y = 15, int health = 100) :
        _position(x, y),
        _dxdt(0),
        _dydt(0),
        _health(health)
    {};
    Position getPosition();
    Velocity getVelocity();
    void setVelocity(float dxdt, float dydt);
    bool getGun();
    void setGun(bool status);
    void move(float dx, float dy);
    
private:
    Position _position;
    float _dxdt;
    float _dydt;
    int _health;
    bool _gun;
};

#endif /* player_model_hpp */
