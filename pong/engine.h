//
//  engine.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//

#include <iostream>
#include "paddle_controllers.h"

bool up_key = false;
bool down_key = false;

void keypress_event(const auto& key){
    std::cout << "key_pressed" << std::endl;
}

void keyrelease_event(const auto& key){
    std::cout << "key_released" << std::endl;
}
