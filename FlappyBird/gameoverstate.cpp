#include "gameoverstate.h"

namespace FlappyBirdClone{
    GameOverState::GameOverState(gameDataRef data)
        : mData(data){
    }

    void GameOverState::init(){
        mData->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        mBackground.setTexture(mData->assets.getTexture("Game Over Background"));
    }

    void GameOverState::handleInput(){
        sf::Event event;

        while(mData->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                mData->window.close();
            }
        }
    }

    void GameOverState::update(float /*dt*/){
    }

    void GameOverState::draw(float /*dt*/){
        mData->window.clear();
        mData->window.draw(mBackground);
        mData->window.display();
    }
}

