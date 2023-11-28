#include "GameState.h"

GameState::GameState(StateStack& stack, Context context)
: State(stack, context) {
}

GameState::~GameState() {
}

bool GameState::update(float dt) {
    mCore.update(dt);
    return true;
}

void GameState::draw() {
    mCore.draw();
}
