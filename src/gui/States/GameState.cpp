#include "GameState.h"

GameState::GameState(StateStack& stack, Context context)
: State(stack, context) {
}

GameState::~GameState() {
}

bool GameState::update(float dt) {
    mCore.update(dt);
    // if (IsKeyPressed(KEY_P)) {
    //     requestStackPush(StateIDs::Settings);
    // }
    // if (IsKeyPressed(KEY_R)) {
    //     requestStackPop();
    //     requestStackPush(StateIDs::Game);
    // }
    return true;
}

void GameState::draw() {
    mCore.draw();
}
