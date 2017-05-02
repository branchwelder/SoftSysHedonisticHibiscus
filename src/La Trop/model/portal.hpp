//
//  portal.hpp
//  La Trop
//
//  Created by Sam Myers on 5/1/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef portal_hpp
#define portal_hpp

#include <stdio.h>
#include "types.h"

struct PortalEntrance {
    bool active;
    Position blockPosition;
    int side; //left 0, top 1, right 2, bottom 3, -1 uninitalized
    Color color;
};

class Portal {
public:
    Portal();
    bool isActive();
    PortalEntrance& getEntrance(int num);
    void moveEntrance(int num, Position position, int side);

private:
    std::pair<PortalEntrance, PortalEntrance> _entrances;
};

#endif /* portal_hpp */
