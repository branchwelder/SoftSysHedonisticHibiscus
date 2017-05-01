//
//  view.hpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef view_hpp
#define view_hpp

#include "square.hpp"
#include "player.hpp"
#include "../model/model.hpp"
#include "../model/types.h"


class View {
public:
    View(Model *model) : _model(model) {};
    void render();

private:
    Model *_model;
    void _renderBlock(Position position, Block block);
    void _renderPlayer(Position position);
};

#endif /* view_hpp */
