//
//  paddles.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//

#include <SFML/Graphics.hpp>
#include "paddle_controllers.h"

class p1_paddle{
private:
    sf::RectangleShape paddle;
    
public:
    p1_paddle(){
        paddle.setSize({50, 100});
        paddle.setFillColor(sf::Color::White);
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(paddle);
    }
};

class p2_paddle{
private:
    sf::RectangleShape paddle;
    
    paddle_controller controller;
    
public:
    p2_paddle(paddle_controller controller){
        paddle.setSize({50, 100});
        paddle.setFillColor(sf::Color::White);
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(paddle);
    }
    
    void get_controller_input(){
        
    }
};
