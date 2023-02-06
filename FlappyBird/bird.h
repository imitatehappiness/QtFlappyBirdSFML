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
        // Инициализация игровых данных
        Bird(gameDataRef data);
        // Отображение птицы
        void draw();
        // Анимация птицы
        void animate(float dt);
        // Обновление
        void update(float dt);
        // Обработка нажатия мыши
        void tap();
        // Получение mBirdSprite
        const sf::Sprite &getSprite() const;
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
