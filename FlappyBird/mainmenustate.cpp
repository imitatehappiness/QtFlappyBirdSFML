#include "mainmenustate.h"

namespace FlappyBirdClone{
    MainMenuState::MainMenuState(gameDataRef data)
        : mData(data){
    }

    void MainMenuState::init(){
        mData->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        mBackground.setTexture(mData->assets.getTexture("Main Menu Background"));

        mData->assets.loadTexture("Main Menu Title Background", MAIN_MENU_TITLE_FILEPATH);
        mTitle.setTexture(mData->assets.getTexture("Main Menu Title Background"));

        mData->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON_FILEPATH);
        mPlayButton.setTexture(mData->assets.getTexture("Play Button"));

        mTitle.setPosition((SCREEN_WIDHT / 2) - (mTitle.getGlobalBounds().width / 2), (mTitle.getGlobalBounds().height / 2));
        mPlayButton.setPosition((SCREEN_WIDHT / 2) - (mPlayButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT/ 2) - (mPlayButton.getGlobalBounds().height / 2));
    }

    void MainMenuState::handleInput(){
        sf::Event event;

        while(mData->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                mData->window.close();
            }
            if(mData->input.isSpriteClicked(mPlayButton, sf::Mouse::Left, mData->window)){
                mData->machine.addState(stateRef(new GameState(mData)), true);
            }
        }
    }

    void MainMenuState::update(float /*dt*/){
    }

    void MainMenuState::draw(float /*dt*/){
        mData->window.clear();
        mData->window.draw(mBackground);
        mData->window.draw(mTitle);
        mData->window.draw(mPlayButton);
        mData->window.display();
    }
}
