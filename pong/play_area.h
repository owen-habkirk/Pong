//
//  play_area.h
//  pong
//
//  Created by Owen Habkirk on 9/4/26.
//

#pragma once
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;

class play_bounds{
private:
    sf::RectangleShape bounds;
    
    void set_position_x(sf::Vector2f position){
        bounds.setPosition({position.x - bounds.getSize().x/2, position.y - bounds.getSize().y/2});
    }
    
public:
    
    play_bounds(){
        bounds.setSize({
            static_cast<float>(window.getSize().y + 100),
            static_cast<float>(window.getSize().y - 10)
        });
        
        set_position_x(window.getView().getCenter());
        bounds.setFillColor(sf::Color::Transparent);
        bounds.setOutlineColor(sf::Color::Green);
        bounds.setOutlineThickness(5);
    }
    
    sf::FloatRect get_bounds(){
        return sf::FloatRect{bounds.getPosition(), bounds.getSize()};
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(bounds);
    }
};
