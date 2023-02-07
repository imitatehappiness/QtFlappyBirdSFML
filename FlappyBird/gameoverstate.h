#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H


#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <state.h>
#include <game.h>
#include <gamestate.h>
#include <defenitions.h>

namespace FlappyBirdClone{
    /*!
     * \class GameOverState
     * \brief Состояние окончания игры
     */
    class GameOverState : public State{
    public:
        GameOverState(gameDataRef data, int score);
        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Спрайт фона
        sf::Sprite mBackground;
        // Спрайт тайтла окончания игры
        sf::Sprite mTitle;
        // Спрайт контейнера окончания игры со счетом и медалью
        sf::Sprite mContainer;
        // Спрайт кнопки "Play"
        sf::Sprite mRetryButton;
        // Спрайт медали
        sf::Sprite mMedal;
        // Текст набранных очков
        sf::Text mScoreText;
        // Текст лучшего результата
        sf::Text mHighScoreText;
        // Набранные очки
        int mScore;
        // Лучший результат
        int mHighScore;
    };
}

#endif // GAMEOVERSTATE_H
