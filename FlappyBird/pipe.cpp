#include "pipe.h"
namespace FlappyBirdClone{

    Pipe::Pipe(gameDataRef data)
        : mData(data){
        mLandHeight = mData->assets.getTexture("Land").getSize().y;
        mPipeSpawnYOffset = 0;
        const unsigned seed = unsigned(std::time(nullptr));
        generator.engine.seed(seed);
    }

    void Pipe::spawnBottomPipe(){
        sf::Sprite sprite(mData->assets.getTexture("Pipe Up"));
        sprite.setPosition(mData->window.getSize().x, mData->window.getSize().y - sprite.getGlobalBounds().height - mPipeSpawnYOffset);

        mPipeSprites.push_back(sprite);
    }

    void Pipe::spawnTopPipe(){
        sf::Sprite sprite(mData->assets.getTexture("Pipe Down"));
        sprite.setPosition(mData->window.getSize().x, -mPipeSpawnYOffset);

        mPipeSprites.push_back(sprite);
    }

    void Pipe::spawnInvisiblePipe(){
        sf::Sprite sprite(mData->assets.getTexture("Pipe Down"));
        sprite.setPosition(mData->window.getSize().x, mData->window.getSize().y - sprite.getGlobalBounds().height);
        sprite.setColor(sf::Color(0, 0, 0, 0));

        mPipeSprites.push_back(sprite);
    }

    void Pipe::spawnScoringPipe(){
        sf::Sprite sprite(mData->assets.getTexture("Scoring Pipe"));
        sprite.setPosition(mData->window.getSize().x, 0);

        mScoringPipeSprites.push_back(sprite);
    }

    void Pipe::movePipes(float dt){
        for(unsigned short i = 0; i < mPipeSprites.size(); ++i){
            if(mPipeSprites[i].getPosition().x < 0 - mPipeSprites[i].getGlobalBounds().width){
                mPipeSprites.erase(mPipeSprites.begin() + i);
            }else{
                float movement = PIPE_MOVEMENT_SPEED * dt;
                mPipeSprites[i].move( -movement, 0);
            }
        }

        for(unsigned short i = 0; i < mScoringPipeSprites.size(); ++i){
            if(mScoringPipeSprites[i].getPosition().x < 0 - mScoringPipeSprites[i].getGlobalBounds().width){
                mScoringPipeSprites.erase(mScoringPipeSprites.begin() + i);
            }else{
                float movement = PIPE_MOVEMENT_SPEED * dt;
                mScoringPipeSprites[i].move( -movement, 0);
            }
        }
    }

    void Pipe::drawPipes(){
        for(unsigned short i = 0; i < mPipeSprites.size(); ++i){
            mData->window.draw(mPipeSprites[i]);
        }
    }

    void Pipe::randomisePipeOffset(){
       std::uniform_int_distribution<size_t> distribution(0, mLandHeight);
       mPipeSpawnYOffset = distribution(generator.engine);
    }

    const std::vector<sf::Sprite>& Pipe::getPipeSprites() const{
        return mPipeSprites;
    }

    std::vector<sf::Sprite>& Pipe::getScoringPipeSprites(){
        return mScoringPipeSprites;
    }
}
