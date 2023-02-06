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
        Land(gameDataRef data);
        void moveLand(float dt);
        void drawLand();
    private:
        // Игровые данные
        gameDataRef mData;
        // Спрайты ландшафта
        std::vector<sf::Sprite> mLandSprites;
    };
}
#endif // LAND_H
