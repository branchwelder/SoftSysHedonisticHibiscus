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

void Model::initPlayer(int x, int y, Player player) {
    _player = std::make_pair(std::make_pair(x, y), player);
}

void Model::movePlayer(int x, int y) {
    _player.first.first = _player.first.first + x;
    _player.first.second = _player.first.second + y;
}
