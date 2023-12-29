#include "GameState.h"
#include "../ResourceHolders/MusicPlayer.h"

#include <thread>

GameState::GameState(StateStack& stack, Context context)
: State(stack, context) {
    getContext().music->play(MusicID::GameTheme);
    initButtons();
}

GameState::~GameState() {
}

bool GameState::update(float dt) {
    mCore.update(dt);
    if (!isLost) {
        for (auto& button : mButtons) {
            button->update(dt);
        }
        if (IsKeyPressed(KEY_TAB)) {
            requestStackPush(StateIDs::Pause);
        }
    }
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
    for (auto& button : mButtons) {
        button->draw();
    }
}

void GameState::initButtons() {
    Button::Ptr pauseButton = std::make_shared<Button>();
    pauseButton->setTexture(TextureHolder::get(TextureID::PauseButton));
    pauseButton->setRect({944, 0, 80, 80});
    pauseButton->setColor(BLANK);
    pauseButton->setCallback([this]() {
        requestStackPush(StateIDs::Pause);
    });
    mButtons.push_back(std::move(pauseButton));
}

GameState::ScoreData::ScoreData(int score)
: score(score) {
}

int GameState::ScoreData::getScore() const {
    return score;
}
