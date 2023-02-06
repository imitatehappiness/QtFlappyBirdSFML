#ifndef PIPE_H
#define PIPE_H

#include <vector>
#include <random>
#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <game.h>
#include <defenitions.h>

namespace FlappyBirdClone{
    /*!
     * \class Pipe
     * \brief Трубы
     */
    class Pipe{
    public:
        // Инициализация игровых данных
        Pipe(gameDataRef data);
        // Генерация нижней части трубы
        void spawnBottomPipe();
        // Генерация верхней части трубы
        void spawnTopPipe();
        // Генерация невидимых труб
        void spawnInvisiblePipe();
        // Перемещение труб
        void movePipes(float dt);
        // Отрисовка труб
        void drawPipes();
        // Смещение трубы
        void randomisePipeOffset();
        // Получение mPipeSprites
        const std::vector<sf::Sprite>& getPipeSprites() const;
    private:
        // Игровые данные
        gameDataRef mData;
        // Спрайты труб
        std::vector<sf::Sprite> mPipeSprites;
        // Высота трубы
        int mLandHeight;
        // Смещение появление трубы
        int mPipeSpawnYOffset;

        struct PRNG{
            std::mt19937 engine;
        };
        // Генератор случайных чисел
        PRNG generator;

    };
}
#endif // PIPE_H
