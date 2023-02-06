#include "land.h"
namespace FlappyBirdClone{

    Land::Land(gameDataRef data)
        : mData(data){

        sf::Sprite sprite(mData->assets.getTexture("Land"));
        sf::Sprite sprite2(mData->assets.getTexture("Land"));

        sprite.setPosition(0, mData->window.getSize().y - sprite.getGlobalBounds().height);
        sprite2.setPosition(sprite.getGlobalBounds().width, mData->window.getSize().y - sprite.getGlobalBounds().height);

        mLandSprites.push_back(sprite);
        mLandSprites.push_back(sprite2);
    }

    void Land::moveLand(float dt){
        for(unsigned short int i = 0; i < mLandSprites.size(); ++i){
            float movement = PIPE_MOVEMENT_SPEED * dt;

            mLandSprites[i].move(- movement, 0.0f);

            if(mLandSprites[i].getPosition().x < 0 - mLandSprites[i].getGlobalBounds().width){
                sf::Vector2f position(mData->window.getSize().x, mLandSprites[i].getPosition().y);

                mLandSprites[i].setPosition(position);
            }
        }
    }

    void Land::drawLand(){
        for(unsigned short int i = 0; i < mLandSprites.size(); ++i){
            mData->window.draw(mLandSprites[i]);
        }
    }

    const std::vector<sf::Sprite>& Land::getSprites() const {
        return mLandSprites;
    }
}
