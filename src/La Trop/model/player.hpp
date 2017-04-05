//
//  player.hpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef player_model_hpp
#define player_model_hpp

#include "../view/player.hpp"

class Player {
public:
    Player(float x = 0, float y = 0, int health = 100) : _x(x), _y(y), _health(health) {};
    bool getGun();
    void setGun(bool status);
    
private:
    float _x;
    float _y;
    int _health;
    bool _gun;
};

#endif /* player_model_hpp */
