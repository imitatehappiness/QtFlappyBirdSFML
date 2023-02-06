#include "bird.h"
namespace FlappyBirdClone{

    Bird::Bird(gameDataRef data)
        : mData(data){
        mAnimationIteration = 0;
        mAnimationFrames.push_back(mData->assets.getTexture("Bird Frame 1"));
        mAnimationFrames.push_back(mData->assets.getTexture("Bird Frame 2"));
        mAnimationFrames.push_back(mData->assets.getTexture("Bird Frame 3"));
        mAnimationFrames.push_back(mData->assets.getTexture("Bird Frame 4"));

        mBirdSprite.setTexture(mAnimationFrames[mAnimationIteration]);
        mBirdSprite.setPosition((mData->window.getSize().x / 4 - (mBirdSprite.getGlobalBounds().width / 2)),
                                (mData->window.getSize().y / 2 - (mBirdSprite.getGlobalBounds().height / 2)));

        mBirdState = BIRD_STATE_STILL;

        sf::Vector2f origin = sf::Vector2f(mBirdSprite.getGlobalBounds().width / 2,
                                           mBirdSprite.getGlobalBounds().height / 2);
        mBirdSprite.setOrigin(origin);
        mRotation = 0.0f;
    }

    void Bird::draw(){
        mData->window.draw(mBirdSprite);
    }

    void Bird::animate(float dt){
        if(mClock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / mAnimationFrames.size()){
            if(mAnimationIteration < mAnimationFrames.size() - 1){
                mAnimationIteration++;
            }else{
                mAnimationIteration = 0;
            }
            mBirdSprite.setTexture(mAnimationFrames[mAnimationIteration]);
            mClock.restart();
        }
    }

    void Bird::update(float dt){
        if(BIRD_STATE_FALLING == mBirdState){
            mBirdSprite.move(0, GRAVITY * dt);
            mRotation += ROTATION_SPEED * dt;
            if(mRotation > MAX_ROTATION){
                mRotation = MAX_ROTATION;
            }
            mBirdSprite.setRotation(mRotation);
        }else if(BIRD_STATE_FLYING == mBirdState){
            mBirdSprite.move(0, -FLYING_SPEED * dt);
            mRotation -= ROTATION_SPEED * dt;
            if(mRotation < -MAX_ROTATION){
                mRotation = -MAX_ROTATION;
            }
            mBirdSprite.setRotation(mRotation);
        }

        if(mMovementClock.getElapsedTime().asSeconds() > FLYING_DURATION){
            mMovementClock.restart();
            mBirdState = BIRD_STATE_FALLING;
        }
    }

    void Bird::tap(){
        mMovementClock.restart();
        mBirdState = BIRD_STATE_FLYING;
    }

    const sf::Sprite& Bird::getSprite() const{
        return mBirdSprite;
    }
}
