#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <state.h>
#include <game.h>
#include <defenitions.h>
#include <mainmenustate.h>

namespace FlappyBirdClone{
    /*!
     * \class SplashState
     * \brief Состояние завставки в начале игры
     */
    class SplashState : public State{
    public:
        SplashState(gameDataRef data);
        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Часы, необходимые для SPLASH_STATE_SHOW_TIME
        sf::Clock mClock;
        // Спрайт фона
        sf::Sprite mBackground;

    };
}
#endif // SPLASHSTATE_H
