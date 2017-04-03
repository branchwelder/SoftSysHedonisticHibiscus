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

typedef std::map<std::pair<int, int>, Block> blockMap;

class Model {
public:
    Model() : _world() {};
    blockMap getWorld();
    void addBlock(int x, int y, Block block);

private:
    blockMap _world;
};

#endif /* model_hpp */
