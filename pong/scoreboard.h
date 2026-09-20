//
//  scoreboard.h
//  pong
//
//  Created by Owen Habkirk on 9/9/26.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class scoreboard{
private:
    sf::Font font;
    sf::Text p1_score;
    sf::Text p2_score;
    bool font_loaded = false;
    
    void center_p1_text(const sf::FloatRect& bounds){
        float bounds_center = bounds.position.x + (bounds.size.x / 2);
        float left_quarter = bounds_center - (bounds.size.x / 4);
        
        p1_score.setPosition({left_quarter - (p1_score.getLocalBounds().size.x / 2), p1_score.getPosition().y});
    }
    
    void center_p2_text(const sf::FloatRect& bounds){
        float bounds_center = bounds.position.x + (bounds.size.x / 2);
        float right_quarter = bounds_center + (bounds.size.x / 4);
        
        p2_score.setPosition({right_quarter - (p1_score.getLocalBounds().size.x / 2), p1_score.getPosition().y});
    }
    
public:
    scoreboard(sf::Vector2f p1_position, sf::Vector2f p2_position, const sf::FloatRect& bounds)
    :p1_score(font), p2_score(font){
        font_loaded = font.openFromFile("pong_assets/Orbitron/orbitron_font.ttf");
        if(font_loaded){
            std::cout << "font loaded" << std::endl;
        }else{
            std::cerr << "failed to load font: " << std::endl;
            return;
        }
        
        p1_score.setCharacterSize(100);
        p2_score.setCharacterSize(100);
        p1_score.setFillColor(sf::Color::White);
        p2_score.setFillColor(sf::Color::White);
        p1_score.setPosition(p1_position);
        p2_score.setPosition(p2_position);
        center_p1_text(bounds);
        center_p2_text(bounds);
        
    }
    
    void set_score(const std::string p1, const std::string p2, const sf::FloatRect& bounds){
        if(!font_loaded){
            return;
        }

        if(p1 != p1_score.getString()){
            center_p1_text(bounds);
        }
        if(p2 != p2_score.getString()){
            center_p2_text(bounds);
        }
        p1_score.setString(p1);
        p2_score.setString(p2);
    }
    
    void draw(sf::RenderWindow& window){
        if(!font_loaded){
            return;
        }

        window.draw(p1_score);
        window.draw(p2_score);
    }
};

class controls{
private:
    sf::Font font;
    sf::Text text;
    bool font_loaded = false;
public:
    controls()
    :text(font){
        font_loaded = font.openFromFile("pong_assets/Orbitron/orbitron_font.ttf");
        if(font_loaded){
            std::cout << "font loaded" << std::endl;
        }else{
            std::cerr << "failed to load controls font" << std::endl;
        }
        text.setString("[1] - Single Player \n [2] - Two Players \n [R] - Reset Ball \n [R x2] - Restart \n [W/S] - Left Paddle Up/Down \n [Up/Down] - Right Paddle Up/Down");
        
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition({5, 5});
    }
    
    void draw(sf::RenderWindow& window){
        if(!font_loaded){
            return;
        }

        window.draw(text);
    }
};
