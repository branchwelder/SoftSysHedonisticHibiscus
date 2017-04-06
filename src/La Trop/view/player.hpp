//
//  player.hpp
//  La Trop
//
//  Created by Hannah Twigg-Smith on 4/4/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef player_view_hpp
#define player_view_hpp


class PlayerView {
public:
    PlayerView(float x, float y);
    void render();
    
private:
    float _x;
    float _y;
};

#endif /* player_view_hpp */
