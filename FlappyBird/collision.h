#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

namespace FlappyBirdClone{
    /*!
     * \class Collision
     * \brief
     */
    class Collision{
    public:
        Collision();
        // Проверка столкновения спрайтов
        bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        // Проверка столкновения спрайтов
        bool checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
    };
}
#endif // COLLISION_H
