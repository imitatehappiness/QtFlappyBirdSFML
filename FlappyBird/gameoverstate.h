#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H


#include <iostream>

#include <SFML/Graphics.hpp>
#include <state.h>
#include <game.h>
#include <defenitions.h>

namespace FlappyBirdClone{
    /*!
     * \class GameOverState
     * \brief Состояние окончания игры
     */
    class GameOverState : public State{
    public:
        GameOverState(gameDataRef data);
        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Спрайт фона
        sf::Sprite mBackground;
    };
}

#endif // GAMEOVERSTATE_H
