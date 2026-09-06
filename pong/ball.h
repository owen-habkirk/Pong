//
//  ball.h
//  pong
//
//  Created by Owen Habkirk on 9/4/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <random>

extern sf::RenderWindow window;

float generate_random_number(float min, float max, float abs_min){
    std:: random_device rd;
    std:: mt19937 gen(rd());
    std:: uniform_int_distribution <> dist(min, max);
    
    while(std::abs(dist(gen)) < abs_min){
        std:: uniform_int_distribution <> dist(min, max);
    }

    return dist(gen);

}

class ball{
private:
    
    sf::CircleShape ball_shape;
    float velocity_x = 0;
    float velocity_y = 0;
    float diameter = 20;
    
public:
    ball(){
        ball_shape.setRadius(10);
        ball_shape.setFillColor(sf::Color::White);
        ball_shape.setPosition(window.getView().getCenter());
        diameter = ball_shape.getRadius() * 2;
    }
    
    void reset(){
        ball_shape.setPosition(window.getView().getCenter());
        velocity_x = 0;
        velocity_y = 0;
    }
    
    void serve(){
        velocity_x = generate_random_number(-700, 700, 600);
        velocity_y = generate_random_number(-400, 400, 300);
    }
    
    void draw(sf::RenderWindow& window){
        ball_shape.setPosition({ball_shape.getPosition().x + velocity_x * delta_time, ball_shape.getPosition().y + velocity_y * delta_time});
        window.draw(ball_shape);
    }
    
    void draw_bounds(sf::RenderWindow& window){
        //window.draw(get_bounds());
    }
    
    sf::FloatRect get_bounds(){
        return sf::FloatRect{ball_shape.getPosition(), {diameter, diameter}};
        
    }
    
    void flip_velocity_x(){
        velocity_x *= -1;
    }
    
    void flip_velocity_y(){
        velocity_y *= -1;
    }
};
