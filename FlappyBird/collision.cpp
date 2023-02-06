#include "collision.h"
namespace FlappyBirdClone{

    Collision::Collision(){

    }

    bool Collision::checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2){
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();

        if(rect1.intersects(rect2)){
            return true;
        }
        return false;
    }

    bool Collision::checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2){
        sprite1.setScale(scale1, scale2);
        sprite2.setScale(scale1, scale2);

        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();

        if(rect1.intersects(rect2)){
            return true;
        }
        return false;
    }
}
