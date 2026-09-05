//
//  main.cpp
//  pong
//
//  Created by Owen Habkirk on 5/17/26.
//

#include <SFML/Graphics.hpp>
#include "engine.h"
#include "paddles.h"

enum pong_gamestate{
    playing,
    paused,
};



sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
sf::RenderWindow window(desktopMode, "Pong", sf::Style::Default);
float delta_time;

int main(){
    sf::Clock delta_clock;
    
    std::cout << window.getSize().x << ", " << window.getSize().y << std::endl;
    
    pong_gamestate gamestate = paused;
    player2_controller controller;
    p1_paddle paddle;
    p2_paddle paddle_2(controller);
    ball ball;
    play_bounds play_bounds;
    

    

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
            ball.draw(window);
            play_bounds.draw(window);
            game_loop(paddle, paddle_2, ball);
            
            window.display();
        }
    }

    return 0;
}
