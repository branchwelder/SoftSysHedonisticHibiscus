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

typedef std::map<std::pair<int, int>, Block> blockMap;
typedef std::pair<std::pair<int, int>, Player> playerPosition;

class Model {
public:
    Model() : _world(), _player() {};
    blockMap getWorld();
    playerPosition getPlayer();
    void addBlock(int x, int y, Block block);
    void initPlayer(int x, int y, Player player);
    void movePlayer(int x, int y);


private:
    blockMap _world;
    playerPosition _player;
};

#endif /* model_hpp */
