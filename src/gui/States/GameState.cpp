#include "GameState.h"
#include "../ResourceHolders/MusicPlayer.h"
#include "GameOverState.h"

#include <fstream>
#include <thread>

const std::string GameState::PATH_TO_SAVE_FILE = "save/gameplay.txt";

GameState::GameState(StateStack& stack, Context context)
: State(stack, context) {
    mCore = std::make_unique<Core>();
    getContext().music->play(MusicID::GameTheme);
    initButtons();
}

GameState::~GameState() {
    if (!isLost) {
        std::ofstream saveFile(PATH_TO_SAVE_FILE);
        saveFile << "true\n";
        mCore->save(saveFile);
        saveFile.close();
    }
}

bool GameState::update(float dt) {
    mCore->update(dt);
    if (!isLost) {
        for (auto& button : mButtons) {
            button->update(dt);
        }
        if (IsKeyPressed(KEY_TAB)) {
            requestStackPush(StateIDs::Pause);
        }
    }
    if (!isLost && mCore->isLost()) {
        isLost = true;
        std::ofstream saveFile(PATH_TO_SAVE_FILE);
        saveFile << "false\n";
        std::thread t([this]() {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(int(Character::DEAD_ANIMATION_TIME * 1000)));
            requestStackPush(StateIDs::GameOver,
                             std::make_unique<GameOverState::ScoreData>(mCore->getScore()));
        });
        t.detach();
    }
    return false;
}

void GameState::draw() {
    mCore->draw();
    for (auto& button : mButtons) {
        button->draw();
    }
}

void GameState::loadGame() {
    std::ifstream saveFile(PATH_TO_SAVE_FILE);
    std::string saveTest;
    saveFile >> saveTest;
    if (saveTest == "true") {
        delete mCore.release();
        mCore = std::make_unique<Core>(saveFile);
    }
}

bool GameState::isResumable() {
    std::ifstream saveFile(PATH_TO_SAVE_FILE);
    std::string saveTest;
    saveFile >> saveTest;
    return saveTest == "true";
}

void GameState::setParameter(BaseParameter::Ptr parameter) {
    auto initParameter = static_cast<GameInit*>(parameter.get());
    if (initParameter->isResume()) {
        loadGame();
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

GameState::GameInit::GameInit(bool resume)
: resume(resume) {
}

bool GameState::GameInit::isResume() const {
    return resume;
}
