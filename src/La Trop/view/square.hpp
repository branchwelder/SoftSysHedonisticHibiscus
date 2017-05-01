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

class SquareView {
public:
    SquareView(float x, float y, Color color);
    void render();

private:
    float _x;
    float _y;
    GLuint _tex;
    Color _color;
};

#endif /* square_hpp */
