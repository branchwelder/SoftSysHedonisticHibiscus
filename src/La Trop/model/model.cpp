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

void Model::addBlock(int x, int y, Block block) {
    _world.insert(std::make_pair(std::make_pair(x, y), block));
}
