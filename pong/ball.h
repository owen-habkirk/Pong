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
extern float delta_time;

int generate_random_number(int min, int max, int abs_min){
    std:: random_device rd;
    std:: mt19937 gen(rd());
    std:: uniform_int_distribution<int> dist(min, max);
    int value;
    
    do{value = dist(gen);}while(std::abs(value) < abs_min);
    

    return value;

}

class ball{
private:
    sf::CircleShape ball_shape;
    float velocity_x = 0;
    float velocity_y = 0;
    float diameter = 20;
    float curve_degree = 0;
    float window_bottom;
    
public:
    ball(): window_bottom(window.getSize().y){
        ball_shape.setRadius(10);
        ball_shape.setFillColor(sf::Color::White);
        ball_shape.setPosition({
            (window.getView().getCenter().x - ball_shape.getRadius()),
            (window.getView().getCenter().y - ball_shape.getRadius())
        });
        diameter = ball_shape.getRadius() * 2;
    }
    
    void reset(){
        ball_shape.setPosition({
            (window.getView().getCenter().x - ball_shape.getRadius()),
            (window.getView().getCenter().y - ball_shape.getRadius())
        });
        velocity_x = 0;
        velocity_y = 0;
        curve_degree = 0;
    }
    
    void update(){
        float y_position = ball_shape.getPosition().y;
        if(y_position < 0){
            ball_shape.setPosition({ball_shape.getPosition().x, diameter});
        }else if(y_position > window_bottom - diameter){
            ball_shape.setPosition({ball_shape.getPosition().x, window_bottom - diameter});
        }
        velocity_y += curve_degree * delta_time;
        ball_shape.setPosition({ball_shape.getPosition().x + velocity_x * delta_time, ball_shape.getPosition().y + velocity_y * delta_time});
        
    }
    
    void serve(){
        if(velocity_x == 0 && velocity_y == 0){
            velocity_x = generate_random_number(-600, 600, 500);
            velocity_y = generate_random_number(-400, 400, 300);
        }
    }
    
    void draw(sf::RenderWindow& window){
        
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
    
    void set_curve(float curve){
        curve_degree = curve * 7;
    }
    
    sf::Vector2f get_position(){
        return ball_shape.getPosition();
    }
    
    float get_velo_x(){
        return velocity_x;
    }
    
    float get_velo_y(){
        return velocity_y;
    }
    
    float get_curve(){
        return curve_degree;
    }
    
    float get_diameter(){
        return diameter;
    }
};
