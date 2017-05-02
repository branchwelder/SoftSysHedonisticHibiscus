//
//  square.hpp
//  La Trop
//
//  Created by Sam Myers on 4/1/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <OpenGL/gl.h>

#ifndef square_hpp
#define square_hpp

#include "color.hpp"
#include "../model/types.h"

class SquareView {
public:
    SquareView(Vector corner, Color color);
    void render();

private:
    Vector _corner;
    GLuint _tex;
    Color _color;
};

#endif /* square_hpp */
