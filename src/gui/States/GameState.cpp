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
    if (!isLost && mCore.isLost()) {
        isLost = true;
        requestStackPush(StateIDs::GameOver, std::make_unique<ScoreData>(mCore.getScore()));
    }
    return true;
}

void GameState::draw() {
    mCore.draw();
}

GameState::ScoreData::ScoreData(int score)
: score(score) {
}

int GameState::ScoreData::getScore() const {
    return score;
}
