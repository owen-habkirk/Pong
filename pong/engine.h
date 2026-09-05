//
//  engine.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//

#pragma once
#include <iostream>
#include "paddle_controllers.h"
#include "paddles.h"
#include "ball.h"
#include "play_area.h"

bool up_key = false;
bool down_key = false;
bool w_key = false;
bool s_key = false;
bool enter_key = false;
bool prev_enter_key = false;
bool r_key = false;

extern sf::RenderWindow window;



void keypress_event(const auto& key){
    
    if(key.code == sf::Keyboard::Key::Up){
        up_key = true;
    }else if(key.code == sf::Keyboard::Key::Down){
        down_key = true;
    }else if(key.code == sf::Keyboard::Key::W){
        w_key = true;
    }else if(key.code == sf::Keyboard::Key::S){
        s_key = true;
    }else if(key.code == sf::Keyboard::Key::Enter){
        enter_key = true;
    }else if(key.code == sf::Keyboard::Key::R){
        r_key = true;
    }
    
    std::cout << "key_pressed" << std::endl;
}

void keyrelease_event(const auto& key){
    
    if(key.code == sf::Keyboard::Key::Up){
        up_key = false;
    }else if(key.code == sf::Keyboard::Key::Down){
        down_key = false;
    }else if(key.code == sf::Keyboard::Key::W){
        w_key = false;
    }else if(key.code == sf::Keyboard::Key::S){
        s_key = false;
    }else if(key.code == sf::Keyboard::Key::Enter){
        enter_key = false;
    }else if(key.code == sf::Keyboard::Key::R){
        r_key = false;
    }
    
    std::cout << "key_released" << std::endl;
}

void handle_input(p1_paddle& paddle, ball& ball){
    if(w_key){
        if(paddle.get_y() - 700 * delta_time >= 0){
            paddle.set_position(paddle.get_x(), paddle.get_y() - 700 * delta_time);
        }
    }else if(s_key){
        if(paddle.get_y() + 700 * delta_time <= (window.getSize().y - 150)){
            paddle.set_position(paddle.get_x(), paddle.get_y() + 700 * delta_time);
        }
    }
    
    if(enter_key != prev_enter_key){
        prev_enter_key = enter_key;
        if(enter_key){
            std::cout << "Enter" << std::endl;
            ball.serve();
        }
    }
    if(r_key){
        ball.reset();
    }
}

void game_loop(p1_paddle& paddle1, p2_paddle& paddle2, ball& ball){
    handle_input(paddle1, ball);
    //paddle1.run(w_key, s_key);
    paddle2.run();
    
}
