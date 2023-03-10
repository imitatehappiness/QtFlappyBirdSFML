#include "inputmanager.h"
namespace FlappyBirdClone{
    InputManager::InputManager(){}

    InputManager::~InputManager(){}

    bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window){
        if(sf::Mouse::isButtonPressed(button)){
            sf::IntRect spriteRec(object.getPosition().x,
                                  object.getPosition().y,
                                  object.getGlobalBounds().width,
                                  object.getGlobalBounds().height);

            if(spriteRec.contains(getMousePosition(window))){
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window){
        return sf::Mouse::getPosition(window);
    }
}
