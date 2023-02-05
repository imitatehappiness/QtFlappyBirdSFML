#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>

#include <state.h>

namespace FlappyBirdClone{
    typedef std::unique_ptr<State> stateRef;
    /*!
     * \class StateMachine
     * \brief Конечный автомат
     */
    class StateMachine{
    public:
        StateMachine();
        ~StateMachine();
        // Добавление новое состояние
        void addState(stateRef newState, bool isReplacing = true);
        // Установка значения mIsRemoving = true для дальнейшего удаления верхнего состояния
        void removeState();
        // Обработка изменений состояний
        void processStateChanged();
        // Получение ссылки на активное состояние конечного автомата
        stateRef& getActiveState();
    private:
        // Стек состояний конечного автомата
        std::stack<stateRef> mStates;
        // Новое состояние
        stateRef mNewState;
        // Удаляем ли состояние
        bool mIsRemoving;
        // Добавляем ли состояние
        bool mIsAdding;
        // Заменяем ли состояние
        bool mIsReplacing;
    };
}


#endif // STATEMACHINE_H
