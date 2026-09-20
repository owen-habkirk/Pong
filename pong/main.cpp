//
//  main.cpp
//  pong
//
//  Created by Owen Habkirk on 5/17/26.
//
#pragma once
#include <SFML/Graphics.hpp>
#include "engine.h"
#include "paddles.h"
#include "scoreboard.h"





float delta_time;

int player_1_score = 0;
int player_2_score = 0;
int player_count = 1;

player2_controller manual_controller;
class ai_controller ai_controller;

sound_effect bounce(
    "pong_assets/bounce.wav",
    15
);

sound_effect score(
    "pong_assets/score.wav",
    1
);

int main(){
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopMode, "Pong", sf::Style::Default);
    sf::Clock delta_clock;

    play_bounds play_bounds(window);
    class scoreboard scoreboard({window.getView().getCenter().x - 200, 50}, {window.getView().getCenter().x + 100, 50}, play_bounds.get_bounds());
    controls controls;
    
    std::cout << window.getSize().x << ", " << window.getSize().y << std::endl;
    
    
    p1_paddle paddle(window);
    p2_paddle paddle_2(window);
    ball ball(window);
    
    if(player_count == 1){
        paddle_2.set_controller(ai_controller);
    }else if(player_count == 2){
        paddle_2.set_controller(manual_controller);
    }
    

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        
        delta_time = delta_clock.restart().asSeconds();
        
        while (const auto event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
                //break;
            }
            
            if(const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
                keypress_event(*key_pressed);
            }
            
            if(const auto* key_released = event->getIf<sf::Event::KeyReleased>()){
                keyrelease_event(*key_released);
            }
        }

       
        if(window.isOpen()){
            paddle.draw(window);
            paddle_2.draw(window);
            play_bounds.draw(window);
            ball.draw(window);
            scoreboard.draw(window);
            controls.draw(window);
            game_loop(paddle, paddle_2, ball, play_bounds, scoreboard, window);
            
            window.display();
        }
    }

    return 0;
}
