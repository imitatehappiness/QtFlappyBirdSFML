#ifndef FLASH_H
#define FLASH_H

#include <SFML/Graphics.hpp>
#include <game.h>
#include <defenitions.h>

namespace FlappyBirdClone{
    /*!
     * \class Flash
     * \brief Вспышка при коллизии
     */
    class Flash{
    public:
        // Инициализация игровых данных и формы вспышки
        Flash(gameDataRef data);
        // Обновление
        void update(float dt);
        // Отображение вспышки
        void draw();
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Прямоугольная форма вспышки
        sf::RectangleShape mShape;
        // Включена ли вспышка
        bool mFlashOn;
    };
}
#endif // FLASH_H
