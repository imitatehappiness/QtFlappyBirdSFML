#include "statemachine.h"

namespace FlappyBirdClone{
    StateMachine::StateMachine(){}

    StateMachine::~StateMachine(){}

    void StateMachine::addState(stateRef newState, bool isReplacing){
        mIsAdding = true;
        mIsReplacing = isReplacing;

        mNewState = std::move(newState);
    }

    void StateMachine::removeState(){
        mIsRemoving = true;
    }

    void StateMachine::processStateChanged(){
        if(mIsRemoving && !mStates.empty()){
            mStates.pop();

            if(!mStates.empty()){
                mStates.top()->resume();
            }
            mIsRemoving = false;
        }

        if(mIsAdding){
            if(!mStates.empty()){
                mIsReplacing ? mStates.pop() : mStates.top()->pause();
            }

            mStates.push(std::move(mNewState));
            mStates.top()->init();

            mIsAdding = false;
        }
    }

    stateRef& FlappyBirdClone::StateMachine::getActiveState(){
        return mStates.top();
    }
}
