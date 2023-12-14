#include "GameState.h"
#include <thread>

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
        std::thread t([this]() {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(int(Character::DEAD_ANIMATION_TIME * 1000)));
            requestStackPush(StateIDs::GameOver, std::make_unique<ScoreData>(mCore.getScore()));
        });
        t.detach();
    }
    return false;
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
