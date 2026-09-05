//
//  paddles.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "paddle_controllers.h"

extern float delta_time;
extern sf::RenderWindow window;

class p1_paddle{
private:
    sf::RectangleShape paddle;
    
    bool w_key = false;
    bool s_key = false;
    
public:
    p1_paddle(){
        paddle.setSize({20, 150});
        paddle.setPosition({800, 300});
        paddle.setFillColor(sf::Color::White);
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(paddle);
    }
    
    void set_position(float x, float y){
        paddle.setPosition({x, y});
    }
    
    float get_x(){return paddle.getPosition().x;}
    float get_y(){return paddle.getPosition().y;}
    

};

class p2_paddle{
private:
    bool up_key = false;
    bool down_key = false;
    
    sf::RectangleShape paddle;
    
    paddle_controller* ptr_controller;
    
public:
    p2_paddle(paddle_controller& controller)
        : ptr_controller(&controller){
        paddle.setSize({20, 150});
        paddle.setFillColor(sf::Color::White);
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(paddle);
    }
    
    void get_controller_input(){
        if(ptr_controller->get_controls() == sf::Keyboard::Key::Up){
            up_key = true;
            down_key = false;
        }else if(ptr_controller->get_controls() == sf::Keyboard::Key::Down){
            up_key = false;
            down_key = true;
        }else if(ptr_controller->get_controls() == std::nullopt){
            up_key = false;
            down_key = false;
        }
    }
    
    void run(){
        get_controller_input();
        if(up_key){
            if(paddle.getPosition().y - 700 * delta_time >= 0){
                paddle.setPosition({paddle.getPosition().x, paddle.getPosition().y - 700 * delta_time});
            }
        }else if(down_key){
            if(paddle.getPosition().y + 700 * delta_time <= (window.getSize().y - 150)){
                paddle.setPosition({paddle.getPosition().x, paddle.getPosition().y + 700 * delta_time});
            }
        }
    }
    
    
};
