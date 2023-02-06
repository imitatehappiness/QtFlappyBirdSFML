#ifndef BIRD_H
#define BIRD_H

#include <vector>

#include <SFML/Graphics.hpp>
#include <defenitions.h>
#include <game.h>

namespace FlappyBirdClone{
    /*!
     * \class Bird
     * \brief
     */
    class Bird{
    public:
        Bird(gameDataRef data);
        void draw();
        void animate(float dt);
        void update(float dt);
        void tap();
    private:
        // Игровые данные
        gameDataRef mData;
        // Спрайт птицы
        sf::Sprite mBirdSprite;
        // Текстуры анимации птицы
        std::vector<sf::Texture> mAnimationFrames;
        // Итератор анимаций
        unsigned int mAnimationIteration;
        // Часы для BIRD_ANIMATION_DURATION
        sf::Clock mClock;
        // Часы для перемещения птицы
        sf::Clock mMovementClock;
        // Текущее состояние птицы
        int mBirdState;
        // Ротация
        float mRotation;
    };
}
#endif // BIRD_H
