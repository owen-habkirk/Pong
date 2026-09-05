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
    
    void set_position_x(float x_position){
        bounds.setPosition({x_position - bounds.getSize().x/2, 0});
    }
    
public:
    
    
    
    play_bounds(){
        bounds.setSize({
            static_cast<float>(window.getSize().y),
            static_cast<float>(window.getSize().y)
        });
        
        set_position_x(window.getView().getCenter().x);
        bounds.setFillColor(sf::Color::Transparent);
        bounds.setOutlineColor(sf::Color::Green);
        bounds.setOutlineThickness(5);
    }
    
    sf::RectangleShape get_bounds(){
        return bounds;
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(bounds);
    }
};
