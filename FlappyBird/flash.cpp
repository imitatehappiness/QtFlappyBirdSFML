#include "flash.h"
namespace FlappyBirdClone{

    Flash::Flash(gameDataRef data)
        : mData(data){
        mShape = sf::RectangleShape(sf::Vector2f(mData->window.getSize()));
        mShape.setFillColor(sf::Color(255, 255, 255, 0));

        mFlashOn = true;
    }

    void Flash::update(float dt){
        if(mFlashOn){
            // алфа цвет * скорость вспышки
            int alpha = (int)mShape.getFillColor().a + (GAME_OVER_FLASH_SPEED * dt);
            if(alpha >= 255){
                alpha = 255;
                mFlashOn = false;
            }
            mShape.setFillColor(sf::Color(255, 255, 255, alpha));
        }else{
            int alpha = (int)mShape.getFillColor().a - (GAME_OVER_FLASH_SPEED * dt);
            if(alpha <= 0){
                alpha = 0;
                mFlashOn = false;
            }
            mShape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
    }

    void Flash::draw(){
        mData->window.draw(mShape);
    }
}
