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

extern sf::RenderWindow window;
extern int player_1_score;
extern int player_2_score;

enum collsion_variables{
    bounds_top,
    bounds_bottom,
    bounds_right,
    bounds_left,
    paddle_p1,
    paddle_p2,
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
    
    if(ball_bounds.findIntersection(paddle_1) && recently_collided != paddle_p1){
        ball.set_curve(ball_bounds.getCenter().y - paddle_1.getCenter().y);
        ball.flip_velocity_x();
        recently_collided = paddle_p1;
        return;
    }else if(ball_bounds.findIntersection(paddle_2) && recently_collided != paddle_p2){
        ball.set_curve(ball_bounds.getCenter().y - paddle_2.getCenter().y);
        ball.flip_velocity_x();
        recently_collided = paddle_p2;
        return;
    }else if(ball_left <= play_bounds_left && recently_collided != bounds_left){
        //ball.flip_velocity_x();
        player_2_score ++;
        ball.reset();
        //recently_collided = bounds_left;
        return;
    }else if(ball_right >= play_bounds_right && recently_collided != bounds_right){
        //ball.flip_velocity_x();
        player_1_score ++;
        ball.reset();
        //recently_collided = bounds_right;
        return;
    }else if(ball_top <= play_bounds_top && recently_collided != bounds_top){
        ball.flip_velocity_y();
        recently_collided = bounds_top;
        return;
    }else if(ball_bottom >= play_bounds_bottom && recently_collided != bounds_bottom){
        ball.flip_velocity_y();
        recently_collided = bounds_bottom;
        return;
    }
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
    }
    
     
}

void handle_input(p1_paddle& paddle, ball& ball){
    if(w_key){
        if(paddle.get_y() - 700 * delta_time >= 0){
            paddle.set_position(paddle.get_x(), paddle.get_y() - 700 * delta_time);
        }
    }else if(s_key){
        if(paddle.get_y() + 700 * delta_time <= (window.getSize().y - 150)){
            paddle.set_position(paddle.get_x(), paddle.get_y() + 700 * delta_time);
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
    
    handle_input(paddle1, ball);
    //paddle1.run(w_key, s_key);
    paddle2.run();
    
    colllision_check(ball, paddle1.get_bounds(), paddle2.get_bounds(), play_bounds.get_bounds());
    
    std::cout << player_1_score << " - " << player_2_score << std::endl;
}
