#ifndef LAND_H
#define LAND_H

#include <vector>

#include <SFML/Graphics.hpp>
#include <game.h>
#include <defenitions.h>

namespace FlappyBirdClone{
    /*!
     * \class Land
     * \brief Ландшафт
     */
    class Land{
    public:
        // Инициализация игровых данных
        Land(gameDataRef data);
        // Перемещение ландшафта
        void moveLand(float dt);
        // Отображение ландшафта
        void drawLand();
        // Получение mLandSprites
        const std::vector<sf::Sprite> &getSprites() const;
    private:
        // Игровые данные
        gameDataRef mData;
        // Спрайты ландшафта
        std::vector<sf::Sprite> mLandSprites;
    };
}
#endif // LAND_H
