//
//  engine.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//

#pragma once
#include <iostream>
#include "paddle_controllers.h"
#include "paddles.h"
#include "ball.h"
#include "play_area.h"

bool up_key = false;
bool down_key = false;
bool w_key = false;
bool s_key = false;
bool enter_key = false;
bool prev_enter_key = false;
bool r_key = false;
bool num1_key = false;
bool num2_key = false;

extern sf::RenderWindow window;
extern int player_1_score;
extern int player_2_score;
extern int player_count;
extern ai_controller ai_controller;
extern player2_controller manual_controller;

float predicted_position;

inline void ai_controller::run_ai(ball& ball, p2_paddle& paddle){
    const sf::Vector2f ball_position = ball.get_position();
    const sf::Vector2f paddle_position = paddle.get_position();
    const float paddle_center_y = paddle_position.y + 75;
    const float ball_velocity_x = ball.get_velo_x();
    const float ball_velocity_y = ball.get_velo_y();
    const float predicted_x_velo = generate_random_number(450, 750, 0);
    
    if((paddle_position.x - ball_position.x) > 250){
        if(ball_velocity_x == 0){
            predicted_position = window.getView().getCenter().y;
        }else{
            predicted_position = ball_position.y + ball_velocity_y * ((paddle_position.x - ball_position.x)/predicted_x_velo);
        }
    }
    
    //std::cout << predicted_position << std::endl;
    
  
    if(paddle_center_y > predicted_position && ball_velocity_x >= 0){
        up_key = true;
        down_key = false;
    }else if(paddle_center_y < predicted_position && ball_velocity_x >= 0){
        up_key = false;
        down_key = true;
    }else{
        up_key = false;
        down_key = false;
    }
}
    
    /*
    if(ball_position.y < paddle_position.y && ball_velocity_x > 0){
        if(ball_velocity_y < 0){
            up_key = true;
            down_key = false;
        }else if(ball_velocity_y > 0){
            up_key = false;
            down_key = false;
        }
    }else if(ball_position.y > paddle_position.y){
        if(ball_velocity_y < 0){
            up_key = false;
            down_key = false;
        }else if(ball_velocity_y > 0){
            up_key = false;
            down_key = true;
        }
    }*/


enum collsion_variables{
    bounds_right,
    bounds_left,
    paddle_p1,
    paddle_p2,
    inter,
    null,
};

collsion_variables recently_collided = null;

void colllision_check(ball& ball, const sf::FloatRect& paddle_1, const sf::FloatRect& paddle_2, const sf::FloatRect& play_bounds){
    const sf::FloatRect ball_bounds = ball.get_bounds();
    const float play_bounds_right = play_bounds.position.x + play_bounds.size.x;
    const float play_bounds_left = play_bounds.position.x;
    const float play_bounds_top = play_bounds.position.y;
    const float play_bounds_bottom = play_bounds.position.y + play_bounds.size.y;
    const float ball_left = ball_bounds.position.x;
    const float ball_right = ball_bounds.position.x + ball_bounds.size.x;
    const float ball_top = ball_bounds.position.y;
    const float ball_bottom = ball_bounds.position.y + ball_bounds.size.y;
    
    if(ball_bounds.findIntersection(paddle_1) && recently_collided != paddle_p1 && recently_collided != inter){
        ball.set_curve(ball_bounds.getCenter().y - paddle_1.getCenter().y);
        ball.flip_velocity_x();
        recently_collided = paddle_p1;
        return;
    }else if(ball_bounds.findIntersection(paddle_2) && recently_collided != paddle_p2 && recently_collided != inter){
        ball.set_curve(ball_bounds.getCenter().y - paddle_2.getCenter().y);
        ball.flip_velocity_x();
        recently_collided = paddle_p2;
        return;
    }else if(ball_left <= play_bounds_left && recently_collided != bounds_left && recently_collided != inter){
        //ball.flip_velocity_x();
        player_2_score ++;
        ball.reset();
        recently_collided = null;
        //recently_collided = bounds_left;
        return;
    }else if(ball_right >= play_bounds_right && recently_collided != bounds_right && recently_collided != inter){
        //ball.flip_velocity_x();
        player_1_score ++;
        ball.reset();
        recently_collided = null;
        //recently_collided = bounds_right;
        return;
    }else if(ball_top <= play_bounds_top  && recently_collided != inter){
        ball.flip_velocity_y();
       
        //recently_collided = bounds_top;
        return;
    }else if(ball_bottom >= play_bounds_bottom && recently_collided != inter){
        ball.flip_velocity_y();
        
        //recently_collided = bounds_bottom;
        return;
    }/*else if(recently_collided != null && recently_collided != inter){
        recently_collided = inter;
        return
    }else if(recently_collided == inter){
        recently_collided = null;
    }*/
};


void keypress_event(const auto& key){
    
    if(key.code == sf::Keyboard::Key::Up){
        up_key = true;
    }else if(key.code == sf::Keyboard::Key::Down){
        down_key = true;
    }else if(key.code == sf::Keyboard::Key::W){
        w_key = true;
    }else if(key.code == sf::Keyboard::Key::S){
        s_key = true;
    }else if(key.code == sf::Keyboard::Key::Enter){
        enter_key = true;
    }else if(key.code == sf::Keyboard::Key::R){
        r_key = true;
    }else if(key.code == sf::Keyboard::Key::Num1){
        num1_key = true;
    }else if(key.code == sf::Keyboard::Key::Num2){
        num2_key = true;
    }
    
    
}

void keyrelease_event(const auto& key){
    
    if(key.code == sf::Keyboard::Key::Up){
        up_key = false;
    }else if(key.code == sf::Keyboard::Key::Down){
        down_key = false;
    }else if(key.code == sf::Keyboard::Key::W){
        w_key = false;
    }else if(key.code == sf::Keyboard::Key::S){
        s_key = false;
    }else if(key.code == sf::Keyboard::Key::Enter){
        enter_key = false;
    }else if(key.code == sf::Keyboard::Key::R){
        r_key = false;
    }else if(key.code == sf::Keyboard::Key::Num1){
        num1_key = false;
    }else if(key.code == sf::Keyboard::Key::Num2){
        num2_key = false;
    }
    
     
}

void handle_input(p1_paddle& paddle, p2_paddle& paddle_2, ball& ball){
    if(w_key){
        if(paddle.get_y() - 700 * delta_time >= 0){
            paddle.set_position(paddle.get_x(), paddle.get_y() - 700 * delta_time);
        }else{
            paddle.set_position(paddle.get_x(), 0);
        }
    }else if(s_key){
        if(paddle.get_y() + 700 * delta_time <= (window.getSize().y - 150)){
            paddle.set_position(paddle.get_x(), paddle.get_y() + 700 * delta_time);
        }else{
            paddle.set_position(paddle.get_x(), window.getSize().y - 150);
        }
    }
    
    if(enter_key != prev_enter_key){
        prev_enter_key = enter_key;
        if(enter_key){
            ball.serve();
        }
    }
    if(r_key){
        ball.reset();
        recently_collided = null;
    }
    
    if(num1_key){
        player_count = 1;
        paddle_2.set_controller(ai_controller);
    }else if(num2_key){
        player_count = 2;
        paddle_2.set_controller(manual_controller);
    }
}

std::once_flag p1_x_position;
std::once_flag p2_x_position;

void game_loop(p1_paddle& paddle1, p2_paddle& paddle2, ball& ball, play_bounds& play_bounds){
    std::call_once(p1_x_position, [&](){
        paddle1.set_x(play_bounds.get_left() + 40);
    });
    std::call_once(p2_x_position, [&]{
        paddle2.set_x(play_bounds.get_right() - 60);
    });
    ball.update();
    
    handle_input(paddle1, paddle2, ball);
    //paddle1.run(w_key, s_key);
    
    paddle2.run(ball);
    
    colllision_check(ball, paddle1.get_bounds(), paddle2.get_bounds(), play_bounds.get_bounds());
    
    std::cout << player_1_score << " - " << player_2_score << std::endl;
}
