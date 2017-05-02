//
//  types.h
//  La Trop
//
//  Created by Sam Myers on 4/29/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef types_h
#define types_h

#include <map>
#include "block.hpp"

typedef std::pair<float, float> Vector;
typedef std::map<Vector, Block> BlockMap;
typedef Vector Velocity;

#endif /* types_h */
