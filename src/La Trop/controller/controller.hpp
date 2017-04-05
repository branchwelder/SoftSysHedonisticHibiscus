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
#include "../view/view.hpp"

class Controller {
public:
    Controller(Model *model, View *view) : _model(model), _view(view) {};
    void handleKeyboard(unsigned char key, int x, int y);
    void handleSpecialKeys(int key, int x, int y);
    
private:
    Model *_model;
    View *_view;
};

#endif /* controller_hpp */
