#include "HomeState.h"
#include <iostream>

HomeState::HomeState(StateStack &stack, Context context)
: State(stack, context) {
    mBackground = std::make_shared<GUITexture>(Rectangle{0, 0, 1024, 640});
    mBackground->setTexture(TextureHolder::get(TextureID::MenuBackground));

    initButtons();
}

HomeState::~HomeState() {
}

bool HomeState::update(float dt) {
    for (auto &button : mButtons) {
        button->update(dt);
    }
    return true;
}

void HomeState::draw() {
    ClearBackground(AppColor::BACKGROUND_1);
    mBackground->draw();
    for (auto &button : mButtons) {
        button->draw();
    }
}

void HomeState::initButtons() {
    Button::Ptr playButton = std::make_shared<Button>();
    playButton->setTexture(TextureHolder::get(TextureID::MenuPlayButton));
    playButton->setSize({199, 68});
    playButton->setColor(BLANK);
    playButton->setCallback([this]() {
        std::cout << "Play button pressed" << std::endl;
    });
    mButtons.push_back(std::move(playButton));

    Button::Ptr settingsButton = std::make_shared<Button>();
    settingsButton->setTexture(TextureHolder::get(TextureID::MenuSettingsButton));
    settingsButton->setSize({199, 68});
    settingsButton->setColor(BLANK);
    settingsButton->setCallback([this]() {
        requestStackPush(StateIDs::Settings);
    });
    mButtons.push_back(std::move(settingsButton));

    Button::Ptr creditsButton = std::make_shared<Button>();
    creditsButton->setTexture(TextureHolder::get(TextureID::MenuCreditsButton));
    creditsButton->setSize({199, 68});
    creditsButton->setColor(BLANK);
    creditsButton->setCallback([this]() {
        requestStackPush(StateIDs::Credits);
    });
    mButtons.push_back(std::move(creditsButton));

    float buttonX = 412;
    float buttonY = 320;
    float buttonGap = 24;

    for (auto &button : mButtons) {
        button->setPosition({buttonX, buttonY});
        buttonY += button->getSize().y + buttonGap;
    }
}
