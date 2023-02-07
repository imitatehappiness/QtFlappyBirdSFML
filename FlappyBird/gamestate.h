#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <state.h>
#include <game.h>
#include <defenitions.h>
#include <pipe.h>
#include <land.h>
#include <bird.h>
#include <collision.h>
#include <flash.h>
#include <hud.h>
#include <gameoverstate.h>

namespace FlappyBirdClone{
    /*!
     * \class GameState
     * \brief Состояние игры
     */
    class GameState : public State{
    public:
        GameState(gameDataRef data);
        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Спрайт фона
        sf::Sprite mBackground;
        // Указатель на объект трубы
        Pipe* mPipe;
        // Указатель на объект ландшафт
        Land* mLand;
        // Указатель на объект птица
        Bird* mBird;
        // Часы для PIPE_SPAWN_FREQUENCY
        sf::Clock mClock;
        // Коллизии столкновения
        Collision mCollision;
        // Выспышка
        Flash* mFlash;
        // Худ
        HUD* mHud;
        // Состояние игры согласно enum GameStates
        int mGameState;
        // Счет
        int mScore;


    };
}
#endif // GAMESTATE_H
