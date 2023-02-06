#include "gamestate.h"

namespace FlappyBirdClone{
    GameState::GameState(gameDataRef data)
        : mData(data){
    }

    void GameState::init(){
        mData->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        mData->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
        mData->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        mData->assets.loadTexture("Land", LAND_FILEPATH);
        mData->assets.loadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        mData->assets.loadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        mData->assets.loadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        mData->assets.loadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

        mLand = new Land(mData);
        mPipe = new Pipe(mData);
        mBird = new Bird(mData);

        mBackground.setTexture(mData->assets.getTexture("Game Background"));
    }

    void GameState::handleInput(){
        sf::Event event;

        while(mData->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                mData->window.close();
            }
            if(mData->input.isSpriteClicked(mBackground, sf::Mouse::Left, mData->window)){
                mBird->tap();
            }
        }
    }

    void GameState::update(float dt){
        mPipe->movePipes(dt);
        mLand->moveLand(dt);
        if(mClock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
            mPipe->randomisePipeOffset();
            mPipe->spawnInvisiblePipe();
            mPipe->spawnBottomPipe();
            mPipe->spawnTopPipe();

            mClock.restart();
        }
        mBird->animate(dt);
        mBird->update(dt);
    }

    void GameState::draw(float /*dt*/){
        mData->window.clear();
        mData->window.draw(mBackground);
        mPipe->drawPipes();
        mLand->drawLand();
        mBird->draw();
        mData->window.display();
    }
}
