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

#define PLAYER_SPEED 5.0f //blocks per second
#define GRAVITY -15.0f // blocks per second squared
#define PLAYER_HITBOX_X 1.0f
#define PLAYER_HITBOX_Y 1.0f

class Model {
public:
    Model() :
        _world(),
        _player(),
        _time(glutGet(GLUT_ELAPSED_TIME)),
        _keyStates{false}
    {};
    BlockMap getWorld();
    Player& getPlayer();
    void addBlock(float x, float y, Block block);
    void updateKeyState(unsigned char key, bool val);
    void update();

private:
    BlockMap _world;
    Player _player;
    int _time;
    bool _keyStates[256];
    int _checkCollision(Position corner1, Position corner2);
    float _handleCollision(float moving, float stationary);
    void _movePlayer(float x, float y);
    void _processKeys();
    void _handlePhysics(float dt);
};

#endif /* model_hpp */
