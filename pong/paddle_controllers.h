//
//  paddle_controllers.h
//  pong
//
//  Created by Owen Habkirk on 9/2/26.
//



class paddle_controller{
protected:
    virtual std::optional<sf::Keyboard::Key> get_controls();
};

class player2_controller : public paddle_controller{

    }
};

class ai_controller : paddle_controller{
    
};
