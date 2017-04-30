//
//  controller.hpp
//  La Trop
//
//  Created by Sam Myers on 4/3/17.
//  Copyright © 2017 Hedonistic Hibiscus. All rights reserved.
//

#ifndef controller_hpp
#define controller_hpp

#include "../model/model.hpp"

class Controller {
public:
    Controller(Model *model): _model(model) {};
    void handleKeyPress(unsigned char key, int x, int y);
    void handleKeyRelease(unsigned char key, int x, int y);
    void handleSpecialKeys(int key, int x, int y);
    
private:
    Model *_model;
};

#endif /* controller_hpp */
