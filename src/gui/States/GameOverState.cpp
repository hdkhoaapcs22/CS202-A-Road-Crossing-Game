#include "GameOverState.h"

GameOverState::GameOverState(StateStack& stack, Context context)
: State(stack, context) {
    mBackground = std::make_shared<GUITexture>(Rectangle{0, 0, 1024, 640});
    mBackground->setTexture(TextureHolder::get(TextureID::GameOver));

    initButtons();
}

GameOverState::~GameOverState() {
}

bool GameOverState::update(float dt) {
    for (auto& button : mButtons) {
        button->update(dt);
    }
    if (IsKeyPressed(KEY_SPACE)) {
        requestStackClear();
        requestStackPush(StateIDs::Game);
    }
    return true;
}

void GameOverState::draw() {
    mBackground->draw();
    for (auto& button : mButtons) {
        button->draw();
    }
    DrawTextEx(FontHolder::get(FontID::Acme, 95), std::to_string(score).c_str(), {514, 256}, 95, 0, WHITE);
}

void GameOverState::setParameter(BaseParameter::Ptr parameter) {
    auto scoreParameter = static_cast<ScoreData*>(parameter.get());
    score = scoreParameter->getScore();
    highScore = 0;
}

void GameOverState::initButtons() {
    Button::Ptr homeButton = std::make_shared<Button>();
    homeButton->setTexture(TextureHolder::get(TextureID::HomeButton));
    homeButton->setSize({199, 69});
    homeButton->setPosition({291, 413});
    homeButton->setColor(BLANK);
    homeButton->setCallback([this]() {
        requestStackClear();
        requestStackPush(StateIDs::Home);
    });
    mButtons.push_back(std::move(homeButton));

    Button::Ptr retryButton = std::make_shared<Button>();
    retryButton->setTexture(TextureHolder::get(TextureID::RetryButton));
    retryButton->setSize({199, 69});
    retryButton->setPosition({534, 413});
    retryButton->setColor(BLANK);
    retryButton->setCallback([this]() {
        requestStackClear();
        requestStackPush(StateIDs::Game);
    });
    mButtons.push_back(std::move(retryButton));
}

GameOverState::ScoreData::ScoreData(int score)
: score(score) {
}

int GameOverState::ScoreData::getScore() const {
    return score;
}