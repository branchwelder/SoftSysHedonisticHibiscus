//
//  model.hpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#include <map>
#include "block.hpp"
#include "player.hpp"
#include "types.h"

#define PLAYER_SPEED 10 //block per second
#define PLAYER_HITBOX_X 1
#define PLAYER_HITBOX_Y 1

class Model {
public:
    Model() :
        _world(),
        _player(),
        _time(glutGet(GLUT_ELAPSED_TIME)),
        _keyStates{false}
    {};
    BlockMap getWorld();
    Player getPlayer();
    void addBlock(float x, float y, Block block);
    int checkBlock(float x, float y);
    void updateKeyState(unsigned char key, bool val);
    void update();

private:
    BlockMap _world;
    Player _player;
    int _time;
    bool _keyStates[256];
    void _processKeys();
    void _movePlayer(float x, float y);
};

#endif /* model_hpp */
