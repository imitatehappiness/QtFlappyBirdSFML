#include "gameoverstate.h"

namespace FlappyBirdClone{
    GameOverState::GameOverState(gameDataRef data, int score)
        : mData(data), mScore(score){
    }

    void GameOverState::init(){

        std::ifstream readFile;
        readFile.open(HIGH_SCORE_FILEPATH);
        if(readFile.is_open()){
            while(!readFile.eof()){
                readFile >> mHighScore;
            }
        }
        readFile.close();

        std::ofstream writeFile;
        writeFile.open(HIGH_SCORE_FILEPATH);
        if(writeFile.is_open()){
            if(mScore > mHighScore){
                mHighScore = mScore;
            }
            writeFile << mHighScore;
        }
        writeFile.close();

        mData->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        mData->assets.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        mData->assets.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

        mBackground.setTexture(mData->assets.getTexture("Game Over Background"));
        mTitle.setTexture(mData->assets.getTexture("Game Over Title"));
        mContainer.setTexture(mData->assets.getTexture("Game Over Body"));
        mRetryButton.setTexture(mData->assets.getTexture("Play Button"));

        mContainer.setPosition((mData->window.getSize().x / 2) - (mContainer.getGlobalBounds().width / 2),
                               (mData->window.getSize().y / 2) - (mContainer.getGlobalBounds().height / 2));
        mTitle.setPosition((mData->window.getSize().x / 2) - (mTitle.getGlobalBounds().width / 2),
                           (mContainer.getPosition().y - mTitle.getGlobalBounds().height * 1.2));
        mRetryButton.setPosition((mData->window.getSize().x / 2) - (mRetryButton.getGlobalBounds().width / 2),
                                 (mContainer.getPosition().y + mContainer.getGlobalBounds().height + (mRetryButton.getGlobalBounds().height * 0.2)));

        mScoreText.setFont(mData->assets.getFont("Flappy Font"));
        mScoreText.setString(std::to_string(mScore));
        mScoreText.setCharacterSize(GAME_OVER_SIZE_SCORE_TEXT);
        mScoreText.setFillColor(sf::Color::White);
        mScoreText.setOrigin(mScoreText.getGlobalBounds().width / 2, mScoreText.getGlobalBounds().height / 2);
        mScoreText.setPosition(mData->window.getSize().x / 10 * 7.25, mData->window.getSize().y / 2.15);

        mHighScoreText.setFont(mData->assets.getFont("Flappy Font"));
        mHighScoreText.setString(std::to_string(mHighScore));
        mHighScoreText.setCharacterSize(GAME_OVER_SIZE_SCORE_TEXT);
        mHighScoreText.setFillColor(sf::Color::White);
        mHighScoreText.setOrigin(mHighScoreText.getGlobalBounds().width / 2, mHighScoreText.getGlobalBounds().height / 2);
        mHighScoreText.setPosition(mData->window.getSize().x / 10 * 7.25, mData->window.getSize().y / 1.78);
    }

    void GameOverState::handleInput(){
        sf::Event event;

        while(mData->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                mData->window.close();
            }

            if(mData->input.isSpriteClicked(mRetryButton, sf::Mouse::Left, mData->window)){
                mData->machine.addState(stateRef(new GameState(mData)), true);
            }
        }
    }

    void GameOverState::update(float /*dt*/){
    }

    void GameOverState::draw(float /*dt*/){
        mData->window.clear();
        mData->window.draw(mBackground);
        mData->window.draw(mTitle);
        mData->window.draw(mContainer);
        mData->window.draw(mRetryButton);
        mData->window.draw(mScoreText);
        mData->window.draw(mHighScoreText);
        mData->window.display();
    }
}

