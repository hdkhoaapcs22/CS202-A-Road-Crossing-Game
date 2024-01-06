#include "SettingsState.h"
#include "../ResourceHolders/MusicPlayer.h"

SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context) {
    mBackground = std::make_shared<GUITexture>(Rectangle{0, 0, 1024, 640});
    mBackground->setTexture(TextureHolder::get(TextureID::PopUpMenu));

    mContent = std::make_shared<GUITexture>(Rectangle{387, 225, 248, 249});
    mContent->setTexture(TextureHolder::get(TextureID::SettingsTexture));

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
    mContent->draw();
    for (auto& button : mButtons) {
        button->draw();
    }
    int volume = getContext().music->getVolume() / 10;
    Vector2 volumeTextBound = MeasureTextEx(FontHolder::get(FontID::Acme, 90), std::to_string(volume).c_str(), 90, 0);
    DrawTextEx(FontHolder::get(FontID::Acme, 100), std::to_string(volume).c_str(),
               {Config::WINDOW_WIDTH / 2 - volumeTextBound.x / 2, 237}, 100, 0, WHITE);
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

    Button::Ptr musicIncreaseButton = std::make_shared<Button>();
    musicIncreaseButton->setTexture(TextureHolder::get(TextureID::RightButton));
    musicIncreaseButton->setRect(Rectangle{661, 249, 47, 72});
    musicIncreaseButton->setColor(BLANK);
    musicIncreaseButton->setCallback([this]() {
        getContext().music->setVolume(std::min(getContext().music->getVolume() + 10, 100));
    });
    mButtons.push_back(std::move(musicIncreaseButton));

    Button::Ptr musicDecreaseButton = std::make_shared<Button>();
    musicDecreaseButton->setTexture(TextureHolder::get(TextureID::LeftButton));
    musicDecreaseButton->setRect(Rectangle{316, 249, 47, 72});
    musicDecreaseButton->setColor(BLANK);
    musicDecreaseButton->setCallback([this]() {
        getContext().music->setVolume(std::max(getContext().music->getVolume() - 10, 0));
    });
    mButtons.push_back(std::move(musicDecreaseButton));

    Button::Ptr muteButton = std::make_shared<Button>();
    muteButton->setTexture(TextureHolder::get(TextureID::NonMutedButton));
    muteButton->setRect(Rectangle{461, 137, 101, 68});
    muteButton->setColor(BLANK);
    muteButton->setCallback([this, muteButton]() {
        if (getContext().music->getMuted()) {
            getContext().music->setMuted(false);
            muteButton->setTexture(TextureHolder::get(TextureID::NonMutedButton));
        } else {
            getContext().music->setMuted(true);
            muteButton->setTexture(TextureHolder::get(TextureID::MutedButton));
        }
    });
    mButtons.push_back(std::move(muteButton));
}
