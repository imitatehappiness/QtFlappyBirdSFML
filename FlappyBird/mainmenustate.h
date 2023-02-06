#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <state.h>
#include <game.h>
#include <defenitions.h>

namespace FlappyBirdClone{
    /*!
     * \class MainMenuState
     * \brief Состояние главного меню
     */
    class MainMenuState : public State{
    public:
        MainMenuState(gameDataRef data);
        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Спрайт фона
        sf::Sprite mBackground;
        // Спрайт тайтла
        sf::Sprite mTitle;
        // Спрайт кнопки
        sf::Sprite mPlayButton;
    };
}
#endif // MAINMENUSTATE_H
