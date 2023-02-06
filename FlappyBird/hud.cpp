#include "hud.h"
namespace FlappyBirdClone{

    HUD::HUD(gameDataRef data)
        : mData(data){

        mScoreText.setFont(mData->assets.getFont("Flappy Font"));
        mScoreText.setString("0");
        mScoreText.setCharacterSize(SIZE_SCORE_TEXT);
        mScoreText.setFillColor(sf::Color::White);
        mScoreText.setOrigin(mScoreText.getGlobalBounds().width / 2, mScoreText.getGlobalBounds().height / 2);
        mScoreText.setPosition(mData->window.getSize().x / 2, mData->window.getSize().y / 8);
    }

    void HUD::draw(){
        mData->window.draw(mScoreText);
    }

    void HUD::updateScore(int score){
        mScoreText.setString(std::to_string(score));
    }
}
