#include "splashstate.h"

namespace FlappyBirdClone{
    SplashState::SplashState(gameDataRef data)
        : mData(data){
    }

    void SplashState::init(){
        mData->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        mBackground.setTexture(mData->assets.getTexture("Splash State Background"));
    }

    void SplashState::handleInput(){
        sf::Event event;

        while(mData->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                mData->window.close();
            }
        }
    }

    void SplashState::update(float dt){
        if(mClock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
            mData->machine.addState(stateRef(new MainMenuState(mData)), true);
        }
    }

    void SplashState::draw(float dt){
        mData->window.clear();
        mData->window.draw(mBackground);
        mData->window.display();
    }
}
