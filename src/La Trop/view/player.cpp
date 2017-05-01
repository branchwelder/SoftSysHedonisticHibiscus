//
//  player.cpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <SOIL/SOIL.h>

#include "player.hpp"
#include "../model/player.hpp"

PlayerView::PlayerView(float x, float y) : _x(x), _y(y) {
    _tex = SOIL_load_OGL_texture
    (
     "doge.jpg",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
}

void PlayerView::render(){
    // Enable 2D textures
    glEnable(GL_TEXTURE_2D);
    
    // Bind texture to the texture target (GL_TEXTURE_2D)
    glBindTexture(GL_TEXTURE_2D, _tex);
    
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);
    glDisable(GL_DEPTH_TEST);
    
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glTexCoord2f(0,0);
    glVertex2f(_x,_y);
    glTexCoord2f(1,0);
    glVertex2f(_x+1, _y);
    glTexCoord2f(1,1);
    glVertex2f(_x+1, _y+1);
    glTexCoord2f(0,1);
    glVertex2f(_x, _y+1);
    glEnd();
    
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
}
