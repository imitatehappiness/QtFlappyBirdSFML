#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

namespace FlappyBirdClone{
    /*!
     * \class InputManager
     * \brief Менеджер ввода
     */
    class InputManager{
    public:
        InputManager();
        ~InputManager();
        // Проверка нажатия на спрайт
        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
        // Получение координат мыши
        sf::Vector2i getMousePosition(sf::RenderWindow& window);
    };
}
#endif // INPUTMANAGER_H
