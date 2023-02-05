#ifndef STATE_H
#define STATE_H

namespace FlappyBirdClone{
    /*!
     * \class State
     * \brief Cостояние конечного автомата
     */
    class State{
    public:
        // Инициализация состояния
        virtual void init() = 0;
        // Обработка всех вводов в текущем состоянии
        virtual void handleInput() = 0;
        // Обновление текущего состояния
        virtual void update(float dt) = 0;
        // Отрисовка состояния
        virtual void draw(float dt /*разница во времени между кадрами*/) = 0;
        // Пауза
        virtual void pause(){}
        // Возобновление
        virtual void resume(){}
    };
}

#endif // STATE_H
