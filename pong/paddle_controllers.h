//
//  paddle_controllers.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//

#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <optional>

class p2_paddle;
class ball;

extern bool up_key;
extern bool down_key;


class paddle_controller{
public:
    virtual std::optional<sf::Keyboard::Key> get_controls(){
        return std::nullopt;
    }
    virtual void run_ai(ball& ball, p2_paddle& paddle, sf::RenderWindow& window){};
};

class player2_controller : public paddle_controller{
public:
    std::optional<sf::Keyboard::Key> get_controls() override {
        if(up_key){
            return sf::Keyboard::Key::Up;
        }else if(down_key){
            return sf::Keyboard::Key::Down;
        }else{
            return std::nullopt;
        }
    }
};

class ai_controller : public paddle_controller{
private:
    bool up_key = false;
    bool down_key = false;
public:
    void run_ai(ball& ball, p2_paddle& paddle, sf::RenderWindow& window) override;
    
    std::optional<sf::Keyboard::Key> get_controls() override {
        if(up_key){
            return sf::Keyboard::Key::Up;
        }else if(down_key){
            return sf::Keyboard::Key::Down;
        }else{
            return std::nullopt;
        }
    }
};
