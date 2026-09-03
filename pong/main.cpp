//
//  main.cpp
//  pong
//
//  Created by Owen Habkirk on 5/17/26.
//

#include <SFML/Graphics.hpp>
#include "engine.h"
#include "paddles.h"

sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
sf::RenderWindow window(desktopMode, "Pong", sf::Style::Default);

int main(){
    
    
    

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            if(const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
                keypress_event(*key_pressed);
            }
            
            if(const auto* key_released = event->getIf<sf::Event::KeyReleased>()){
                keyrelease_event(*key_released);
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}

