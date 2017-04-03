//
//  view.hpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef view_hpp
#define view_hpp

#include "../model/model.hpp"

class View {
public:
    View(Model *model) : _model(model) {};
    void render();

private:
    Model *_model;
};

#endif /* view_hpp */
