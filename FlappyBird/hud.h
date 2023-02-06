#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <defenitions.h>
#include <game.h>

namespace FlappyBirdClone{
    /*!
     * \brief The HUD class
     */
    class HUD{
    public:
        // Инициализация игровых данных
        HUD(gameDataRef data);
        // Отображение счета
        void draw();
        // Обновление счета
        void updateScore(int score);
    private:
        // Cсылка на данные игры
        gameDataRef mData;
        // Тест счета
        sf::Text mScoreText;
    };
}
#endif // HUD_H
