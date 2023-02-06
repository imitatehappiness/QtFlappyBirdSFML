#include "game.h"

#include <splashstate.h>

namespace FlappyBirdClone{
    Game::Game(int widht, int height, std::string title){
        sf::Image icon;
        if (icon.loadFromFile("resources/icons/ninja.ico")){
            std::cout<< "asdasd" << std::endl;
            mData->window.setIcon(32, 32, icon.getPixelsPtr());
        }

        mData->window.create(sf::VideoMode(widht, height), title, sf::Style::Close | sf::Style::Titlebar);
        mData->machine.addState(stateRef(new SplashState(mData)));
        run();
    }

    void Game::run(){
        float newTime, frameTime, interpolation;

        float currentTime = mClock.getElapsedTime().asSeconds();
        // Накопитель времен кадров
        float accumulator = 0.0f;

        while (mData->window.isOpen()){
            // Обработка любых произошедших изменений
            mData->machine.processStateChanged();
            newTime = mClock.getElapsedTime().asSeconds();
            // Прошедшее время ( время кадра )
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f){
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while(accumulator >= dt){
                // Обработка ввода для активновго состояния  и его обновление
                mData->machine.getActiveState()->handleInput();
                mData->machine.getActiveState()->update(dt);

                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            // Отрисовка активного состояния
            mData->machine.getActiveState()->draw(interpolation);
        }
    }
}
