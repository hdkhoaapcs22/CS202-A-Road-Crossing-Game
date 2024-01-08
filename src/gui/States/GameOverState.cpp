#include "GameOverState.h"
#include "GameState.h"
#include <fstream>

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
        this->restartGame();
    }
    return true;
}

void GameOverState::draw() {
    mBackground->draw();
    for (auto& button : mButtons) {
        button->draw();
    }
    DrawTextEx(FontHolder::get(FontID::Acme, 95), std::to_string(score).c_str(), {514, 256}, 95, 0, WHITE);
    DrawTextEx(FontHolder::get(FontID::Acme, 42), std::to_string(highScore).c_str(), {571, 361}, 42, 0, WHITE);
}

void GameOverState::setParameter(BaseParameter::Ptr parameter) {
    auto scoreParameter = static_cast<ScoreData*>(parameter.get());
    score = scoreParameter->getScore();

    std::ifstream fin("save/local.txt");
    if (!fin.is_open()) {
        std::ofstream fout("save/local.txt");
        fout << 0;
        fout.close();
        fin.open("save/local.txt");
    }
    fin >> highScore;
    fin.close();
    if (score > highScore) {
        std::ofstream fout("save/local.txt");
        fout << score;
        highScore = score;
        fout.close();
    }

    darkMode = scoreParameter->isDarkMode();
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
        this->restartGame();
    });
    mButtons.push_back(std::move(retryButton));
}

void GameOverState::restartGame() {
    requestStackClear();
    requestStackPush(StateIDs::Game, std::make_unique<GameState::GameInit>(false, darkMode));
}

GameOverState::ScoreData::ScoreData(int score, bool darkMode)
: score(score), darkMode(darkMode) {
}

int GameOverState::ScoreData::getScore() const {
    return score;
}

bool GameOverState::ScoreData::isDarkMode() const {
    return darkMode;
}
