#include "State.h"
#include "../StateStack.h"

State::State(StateStack &stack, Context context)
: mStack(&stack)
, mContext(context) {
}

State::~State() {
}

void State::setParameter(BaseParameter* parameter) {
}

void State::requestStackPush(StateIDs stateID) {
    mStack->pushState(stateID);
}

void State::requestStackPush(StateIDs stateID, BaseParameter* parameter) {
    mStack->pushParameterizedState(stateID, parameter);
}

void State::requestStackPop() {
    mStack->popState();
}

void State::requestStackClear() {
    mStack->clearStates();
}
