#include "gamestate.h"

namespace FlappyBirdClone{
    GameState::GameState(gameDataRef data)
        : mData(data){
    }

    void GameState::init(){
        mData->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        mData->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
        mData->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        mData->assets.loadTexture("Scoring Pipe", PIPE_SCORING_FILEPATH);
        mData->assets.loadTexture("Land", LAND_FILEPATH);
        mData->assets.loadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        mData->assets.loadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        mData->assets.loadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        mData->assets.loadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        mData->assets.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

        if(!mHitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)){
            std::cout << "Error loading Hit Sound Effect" << std::endl;
        }
        if(!mPointSoundBuffer.loadFromFile(POINTS_SOUND_FILEPATH)){
            std::cout << "Error loading Point Sound Effect" << std::endl;
        }
        if(!mWingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)){
            std::cout << "Error loading Wing Sound Effect" << std::endl;
        }

        mHitSound.setBuffer(mHitSoundBuffer);
        mPointSound.setBuffer(mPointSoundBuffer);
        mWingSound.setBuffer(mWingSoundBuffer);

        mLand = new Land(mData);
        mPipe = new Pipe(mData);
        mBird = new Bird(mData);
        mFlash = new Flash(mData);
        mHud = new HUD(mData);

        mBackground.setTexture(mData->assets.getTexture("Game Background"));

        mScore = 0;
        mHud->updateScore(mScore);

        mGameState = GameStates::eReady;
    }

    void GameState::handleInput(){
        sf::Event event;

        while(mData->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                mData->window.close();
            }
            if(mData->input.isSpriteClicked(mBackground, sf::Mouse::Left, mData->window)){
                if(mGameState != GameStates::eGameOver){
                    mGameState = GameStates::ePlaying;
                    mBird->tap();
                    mWingSound.play();
                }
            }
        }
    }

    void GameState::update(float dt){
        if(mGameState != GameStates::eGameOver){
            mBird->animate(dt);
            mLand->moveLand(dt);
        }

        if(mGameState == GameStates::ePlaying){
            mPipe->movePipes(dt);
            if(mClock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
                mPipe->randomisePipeOffset();
                mPipe->spawnInvisiblePipe();
                mPipe->spawnBottomPipe();
                mPipe->spawnTopPipe();
                mPipe->spawnScoringPipe();

                mClock.restart();
            }
            mBird->update(dt);
            std::vector<sf::Sprite> landSprites = mLand->getSprites();
            for(unsigned short int i = 0; i < landSprites.size(); ++i){
               if(mCollision.checkSpriteCollision(mBird->getSprite(), 0.8f, landSprites[i], 1.0f)){
                    mGameState = GameStates::eGameOver;
                    mHitSound.play();
                    mClock.restart();
                }
            }

            std::vector<sf::Sprite> pipeSprites = mPipe->getPipeSprites();
            for(unsigned short int i = 0; i < pipeSprites.size(); ++i){
               if(mCollision.checkSpriteCollision(mBird->getSprite(), 0.5f, pipeSprites[i], 1.0f)){
                    mGameState = GameStates::eGameOver;
                    mHitSound.play();
                    mClock.restart();
                }
            }

            if(mGameState == GameStates::ePlaying){
                std::vector<sf::Sprite>& pipeScoringSprites = mPipe->getScoringPipeSprites();
                for(unsigned short int i = 0; i < pipeScoringSprites.size(); ++i){
                   if(mCollision.checkSpriteCollision(mBird->getSprite(), 0.5f, pipeScoringSprites[i], 1.0f)){
                        mScore++;
                        mHud->updateScore(mScore);
                        pipeScoringSprites.erase(pipeScoringSprites.begin() + i);
                        mPointSound.play();
                   }
                }
            }
        }

        if(mGameState == GameStates::eGameOver){
            mFlash->update(dt);
            if(mClock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER){
                mData->machine.addState(stateRef(new GameOverState(mData, mScore)), true);
            }
        }
    }

    void GameState::draw(float /*dt*/){
        mData->window.clear();
        mData->window.draw(mBackground);
        mPipe->drawPipes();
        mLand->drawLand();
        mBird->draw();
        mFlash->draw();
        mHud->draw();
        mData->window.display();
    }
}
