//
//  block.hpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef block_hpp
#define block_hpp

#include "../view/color.hpp"

class Block {
public:
    Block(Color color) : _color(color) {};
    Color getColor();

private:
    Color _color;
};

#endif /* block_hpp */
