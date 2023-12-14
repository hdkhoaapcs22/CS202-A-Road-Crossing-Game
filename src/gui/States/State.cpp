#include "State.h"
#include "../StateStack.h"

State::State(StateStack &stack, Context context)
: mStack(&stack)
, mContext(context) {
}

State::~State() {
}

void State::setParameter(BaseParameter::Ptr parameter) {
}

void State::requestStackPush(StateIDs stateID) {
    mStack->pushState(stateID);
}

void State::requestStackPush(StateIDs stateID, BaseParameter::Ptr parameter) {
    mStack->pushParameterizedState(stateID, std::move(parameter));
}

void State::requestStackPop() {
    mStack->popState();
}

void State::requestStackClear() {
    mStack->clearStates();
}
