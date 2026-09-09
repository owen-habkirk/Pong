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
    sf::RectangleShape midline;
    sf::CircleShape center_ring;
    
    float left = 0;
    float right = 0;
    
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
        
        left = bounds.getPosition().x;
        right = bounds.getPosition().x + bounds.getSize().x;
        
        midline.setSize({3, static_cast<float>(window.getSize().y)});
        midline.setPosition({window.getView().getCenter().x, 0});
        midline.setFillColor(sf::Color::Green);
        
        center_ring.setRadius(80);
        center_ring.setPosition({window.getView().getCenter().x - center_ring.getRadius(), window.getView().getCenter().y - center_ring.getRadius()});
        center_ring.setFillColor(sf::Color::Transparent);
        center_ring.setOutlineColor(sf::Color::Green);
        center_ring.setOutlineThickness(3);
    }
    
    sf::FloatRect get_bounds(){
        return sf::FloatRect{bounds.getPosition(), bounds.getSize()};
    }
    
    void draw(sf::RenderWindow& window){
        window.draw(bounds);
        window.draw(center_ring);
        window.draw(midline);
        
    }
    
    float get_left(){return left;}
    float get_right(){return right;}
};
