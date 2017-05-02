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

#define JUMP_VELOCITY 15 // blocks per second

class Player {
public:
    Player(float x = 15, float y = 15, int health = 100) :
        _position(x, y),
        _activeVelocity(Velocity(0, 0)),
        _passiveVelocity(Velocity(0, 0)),
        _health(health),
        onGround(false)
    {};
    Vector getPosition();
    Velocity getVelocity();
    void setActiveVelocity(float dxdt, float dydt);
    void changePassiveVelocity(float dxdt, float dydt);
    void resetPassiveVelocity();
    bool getGun();
    void setGun(bool status);
    void move(float dx, float dy);
    void jump();
    bool onGround;
    
private:
    Vector _position;
    Velocity _activeVelocity;
    Velocity _passiveVelocity;
    int _health;
    bool _gun;
};

#endif /* player_model_hpp */
