#include "SettingsState.h"

SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context) {
    mBackground = std::make_shared<GUITexture>(Rectangle{0, 0, 1024, 640});
    mBackground->setTexture(TextureHolder::get(TextureID::PopUpMenu));

    initButtons();
}

SettingsState::~SettingsState() {
}

bool SettingsState::update(float dt) {
    for (auto& button : mButtons) {
        button->update(dt);
    }
    return false;
}

void SettingsState::draw() {
    ClearBackground(AppColor::BACKGROUND_1);
    mBackground->draw();
    for (auto& button : mButtons) {
        button->draw();
    }
}

void SettingsState::initButtons() {
    Button::Ptr closeButton = std::make_shared<Button>();
    closeButton->setTexture(TextureHolder::get(TextureID::PopUpCloseButton));
    closeButton->setSize({53, 46});
    closeButton->setPosition({853, 67});
    closeButton->setColor(BLANK);
    closeButton->setCallback([this]() {
        requestStackPop();
    });
    mButtons.push_back(std::move(closeButton));
}
