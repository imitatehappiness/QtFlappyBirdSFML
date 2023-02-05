#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include <statemachine.h>
#include <assetmanager.h>
#include <inputmanager.h>

namespace FlappyBirdClone{
    // Структура игровых данных
    struct GameData{
        // Конечный автомат
        StateMachine machine;
        // Окно рендеринга
        sf::RenderWindow window;
        // Менеджер активов
        AssetManager assets;
        // Менеджер ввода
        InputManager input;
    };

    typedef std::shared_ptr<GameData> gameDataRef;

    /*!
     * \class Game
     * \brief Игровой класс
     */
    class Game{
    public:
        // Инициализация окна
        Game(int widht, int height, std::string title);
    private:
        // Частота кадров
        const float dt = 1.0 / 60.0f;
        // Часы, необходимые для обработки кадров
        sf::Clock mClock;
        // Экземпляр указателя на игровые данные
        gameDataRef mData = std::make_shared<GameData>();
        // Запуск игры
        void run();
    };
}
#endif // GAME_H
