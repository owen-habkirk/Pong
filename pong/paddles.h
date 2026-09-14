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
        paddle.setPosition({700, window.getView().getCenter().y - paddle.getSize().y/2});
        paddle.setFillColor(sf::Color::White);
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(paddle);
    }
    
    void set_position(float x, float y){
        paddle.setPosition({x, y});
    }
    
    void set_x(float x){
        paddle.setPosition({x, paddle.getPosition().y});
    }
    
    float get_x(){return paddle.getPosition().x;}
    float get_y(){return paddle.getPosition().y;}
    
    sf::FloatRect get_bounds(){
        return sf::FloatRect{paddle.getPosition(), paddle.getSize()};
    }
    

    

};

class p2_paddle{
private:
    bool up_key = false;
    bool down_key = false;
    
    sf::RectangleShape paddle;
    
    paddle_controller* ptr_controller = nullptr;
    
public:
    p2_paddle(){
        paddle.setSize({20, 150});
        paddle.setPosition({1000, window.getView().getCenter().y - paddle.getSize().y/2});
        paddle.setFillColor(sf::Color::White);
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(paddle);
    }
    
    void get_controller_input(){
        //std::cout << "control" << std::endl;
        if(ptr_controller->get_controls() == sf::Keyboard::Key::Up){
            //std::cout << "up" << std::endl;
            up_key = true;
            down_key = false;
        }else if(ptr_controller->get_controls() == sf::Keyboard::Key::Down){
            //std::cout << "down" << std::endl;
            up_key = false;
            down_key = true;
        }else if(ptr_controller->get_controls() == std::nullopt){
            //std::cout << "null" << std::endl;
            up_key = false;
            down_key = false;
        }
    }
    
    void run(ball& ball){
        if(ptr_controller == nullptr){
            return;
        }
        //std::cout << "run" << std::endl;
        const float min_position = window.getSize().y - 150;
        
        ptr_controller->run_ai(ball, *this);
        
        get_controller_input();
        if(up_key){
            
            if(paddle.getPosition().y - 700 * delta_time >= 0){
                paddle.setPosition({paddle.getPosition().x, paddle.getPosition().y - 700 * delta_time});
            }else{
                paddle.setPosition({paddle.getPosition().x, 0});
            }
        }else if(down_key){

            if(paddle.getPosition().y + 700 * delta_time <= min_position){
                paddle.setPosition({paddle.getPosition().x, paddle.getPosition().y + 700 * delta_time});
            }else{
                paddle.setPosition({paddle.getPosition().x, min_position});
            }
        }
    }
    
    sf::FloatRect get_bounds(){
        return sf::FloatRect{paddle.getPosition(), paddle.getSize()};
    }
    
    void set_x(float x){
        paddle.setPosition({x, paddle.getPosition().y});
    }
    
    sf::Vector2f get_position(){
        return paddle.getPosition();
    }
    
    void set_controller(paddle_controller& controller){
        ptr_controller = &controller;
    }
};
