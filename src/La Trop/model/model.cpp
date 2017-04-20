//
//  model.cpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include "model.hpp"

blockMap Model::getWorld() {
    return _world;
}

playerPosition Model::getPlayer() {
    return _player;
}

void Model::addBlock(int x, int y, Block block) {
    _world.insert(std::make_pair(std::make_pair(x, y), block));
}

int Model::checkBlock(int x, int y) {
    // x and y are delta in position, so we need the players
    // actual position plus the change to compare with blocks
    int newX = _player.first.first + x;
    int newY = _player.first.second + y;
    
    int exists = _world.count(std::make_pair(newX, newY));
    if (exists) {
        return 1;
    }
    return 0;
}

void Model::initPlayer(int x, int y, Player player) {
    _player = std::make_pair(std::make_pair(x, y), player);
}

void Model::movePlayer(int x, int y) {
    // check to not overlap a block
    if (checkBlock(x, y) == 0) {
        _player.first.first = _player.first.first + x;
        _player.first.second = _player.first.second + y;
    }
}
