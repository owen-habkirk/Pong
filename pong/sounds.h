//
//  sounds.h
//  pong
//
//  Created by Owen Habkirk on 9/8/26.
//
#pragma once
#include <SFML/Audio.hpp>
#include <string>

class sound_effect{
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    
public:
    sound_effect(const std::string& file, float pitch)
    :sound(buffer){
        if(buffer.loadFromFile(file)){
            std::cout << "load succes" << std::endl;
            sound.setPitch(pitch);
            sound.setVolume(100);
        }else{
            std::cout << "failed to load sound" << std::endl;
        }
    }
    
    bool is_playing(){
        return sound.getStatus() == sf::SoundSource::Status::Playing;
    }
    
    void play(){
        if(!is_playing()){
            sound.play();
        }
    }
};
