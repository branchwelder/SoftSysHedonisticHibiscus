//
//  view.cpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <OpenGL/gl.h>
#include "view.hpp"
#include "square.hpp"

void View::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (auto it : _model->getWorld()) {
        int x = it.first.first;
        int y = it.first.second;
        Color color = it.second.getColor();

        Square square(x, y, color);
        square.render();
    }
}
