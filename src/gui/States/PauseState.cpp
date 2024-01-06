#include "PauseState.h"

#include <thread>

PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context) {
    mBackground = std::make_shared<GUITexture>(Rectangle{0, 0, 1024, 640});
    mBackground->setTexture(TextureHolder::get(TextureID::SmallPopUpMenu));

    initButtons();
}

PauseState::~PauseState() {
}

bool PauseState::update(float dt) {
    if (IsKeyPressed(KEY_TAB)) {
        requestStackPop();
        requestStackPush(StateIDs::Countdown);
    }
    for (auto& button : mButtons) {
        button->update(dt);
    }
    return false;
}

void PauseState::draw() {
    mBackground->draw();
    for (auto& button : mButtons) {
        button->draw();
    }
}

void PauseState::initButtons() {
    Button::Ptr resumeButton = std::make_shared<Button>();
    resumeButton->setTexture(TextureHolder::get(TextureID::ResumeButton));
    resumeButton->setSize({199, 68});
    resumeButton->setColor(BLANK);
    resumeButton->setCallback([this]() {
        requestStackPop();
        requestStackPush(StateIDs::Countdown);
    });
    mButtons.push_back(std::move(resumeButton));

    Button::Ptr homeButton = std::make_shared<Button>();
    homeButton->setTexture(TextureHolder::get(TextureID::HomeButton));
    homeButton->setSize({199, 68});
    homeButton->setColor(BLANK);
    homeButton->setCallback([this]() {
        requestStackPop();
        requestStackPop();
        requestStackPush(StateIDs::Home);
    });
    mButtons.push_back(std::move(homeButton));

    Button::Ptr settingsButton = std::make_shared<Button>();
    settingsButton->setTexture(TextureHolder::get(TextureID::MenuSettingsButton));
    settingsButton->setSize({199, 68});
    settingsButton->setColor(BLANK);
    settingsButton->setCallback([this]() {
        requestStackPush(StateIDs::Settings);
    });
    mButtons.push_back(std::move(settingsButton));

    float buttonX = 412;
    float buttonY = 230;
    float buttonGap = 31;
    for (auto& button : mButtons) {
        button->setPosition({buttonX, buttonY});
        buttonY += button->getSize().y + buttonGap;
    }
}
