#include "HomeState.h"
#include "../ResourceHolders/MusicPlayer.h"
#include "GameState.h"

HomeState::HomeState(StateStack &stack, Context context)
: State(stack, context) {
    mBackground = std::make_shared<GUITexture>(Rectangle{0, 0, 1024, 640});
    mBackground->setTexture(TextureHolder::get(TextureID::MenuBackground));

    initButtons();

    getContext().music->play(MusicID::MenuTheme);
}

HomeState::~HomeState() {
}

bool HomeState::update(float dt) {
    switch (mMenuState) {
        case MenuState::Main:
            for (auto &button : mMainButtons) {
                button->update(dt);
            }
            break;
        case MenuState::Resume:
            for (auto &button : mResumeButtons) {
                button->update(dt);
            }
            break;
        case MenuState::ModeChoosing:
            for (auto &button : mModeChoosingButtons) {
                button->update(dt);
            }
            break;
    }
    return false;
}

void HomeState::draw() {
    ClearBackground(AppColor::BACKGROUND_1);
    mBackground->draw();
    switch (mMenuState) {
        case MenuState::Main:
            for (auto &button : mMainButtons) {
                button->draw();
            }
            break;
        case MenuState::Resume:
            for (auto &button : mResumeButtons) {
                button->draw();
            }
            break;
        case MenuState::ModeChoosing:
            for (auto &button : mModeChoosingButtons) {
                button->draw();
            }
            break;
    }
}

void HomeState::initButtons() {
    // Main buttons
    Button::Ptr playButton = std::make_shared<Button>();
    playButton->setTexture(TextureHolder::get(TextureID::MenuPlayButton));
    playButton->setSize({199, 68});
    playButton->setColor(BLANK);
    playButton->setCallback([this]() {
        this->mMenuState = MenuState::Resume;
    });
    mMainButtons.push_back(std::move(playButton));

    Button::Ptr settingsButton = std::make_shared<Button>();
    settingsButton->setTexture(TextureHolder::get(TextureID::MenuSettingsButton));
    settingsButton->setSize({199, 68});
    settingsButton->setColor(BLANK);
    settingsButton->setCallback([this]() {
        requestStackPush(StateIDs::Settings);
    });
    mMainButtons.push_back(std::move(settingsButton));

    Button::Ptr creditsButton = std::make_shared<Button>();
    creditsButton->setTexture(TextureHolder::get(TextureID::MenuCreditsButton));
    creditsButton->setSize({199, 68});
    creditsButton->setColor(BLANK);
    creditsButton->setCallback([this]() {
        requestStackPush(StateIDs::Credits);
    });
    mMainButtons.push_back(std::move(creditsButton));

    float buttonX = 412;
    float buttonY = 320;
    float buttonGap = 24;

    for (auto &button : mMainButtons) {
        button->setPosition({buttonX, buttonY});
        buttonY += button->getSize().y + buttonGap;
    }

    // Resume buttons
    Button::Ptr newGameButton = std::make_shared<Button>();
    newGameButton->setTexture(TextureHolder::get(TextureID::MenuNewGameButton));
    newGameButton->setSize({240, 68});
    newGameButton->setColor(BLANK);
    newGameButton->setCallback([this]() {
        this->mMenuState = MenuState::ModeChoosing;
    });
    mResumeButtons.push_back(std::move(newGameButton));

    Button::Ptr continueButton = std::make_shared<Button>();
    continueButton->setTexture(TextureHolder::get(TextureID::MenuContinueButton));
    continueButton->setSize({240, 68});
    continueButton->setColor(BLANK);
    continueButton->setCallback([this]() {
        requestStackPop();
        requestStackPush(StateIDs::Game, std::make_unique<GameState::GameInit>(true));
    });
    if (!GameState::isResumable()) {
        continueButton->deactivate();
    }
    mResumeButtons.push_back(std::move(continueButton));

    Button::Ptr backButton = std::make_shared<Button>();
    backButton->setTexture(TextureHolder::get(TextureID::MenuGoBackButton));
    backButton->setSize({240, 68});
    backButton->setColor(BLANK);
    backButton->setCallback([this]() {
        this->mMenuState = MenuState::Main;
    });
    mResumeButtons.push_back(std::move(backButton));

    buttonX = 392;
    buttonY = 320;
    buttonGap = 24;

    for (auto &button : mResumeButtons) {
        button->setPosition({buttonX, buttonY});
        buttonY += button->getSize().y + buttonGap;
    }

    // Mode buttons

    Button::Ptr classicModeButton = std::make_shared<Button>();
    classicModeButton->setTexture(TextureHolder::get(TextureID::ClassicModeButton));
    classicModeButton->setSize({240, 68});
    classicModeButton->setColor(BLANK);
    classicModeButton->setCallback([this]() {
        requestStackPop();
        requestStackPush(StateIDs::Game);
    });
    mModeChoosingButtons.push_back(std::move(classicModeButton));

    Button::Ptr darkModeButton = std::make_shared<Button>();
    darkModeButton->setTexture(TextureHolder::get(TextureID::DarkModeButton));
    darkModeButton->setSize({240, 68});
    darkModeButton->setColor(BLANK);
    darkModeButton->setCallback([this]() {
        requestStackPop();
        requestStackPush(StateIDs::Game, std::make_unique<GameState::GameInit>(false, true));
    });
    mModeChoosingButtons.push_back(std::move(darkModeButton));

    backButton = std::make_shared<Button>();
    backButton->setTexture(TextureHolder::get(TextureID::MenuGoBackButton));
    backButton->setSize({240, 68});
    backButton->setColor(BLANK);
    backButton->setCallback([this]() {
        this->mMenuState = MenuState::Main;
    });
    mModeChoosingButtons.push_back(std::move(backButton));

    buttonX = 392;
    buttonY = 320;
    buttonGap = 24;

    for (auto &button : mModeChoosingButtons) {
        button->setPosition({buttonX, buttonY});
        buttonY += button->getSize().y + buttonGap;
    }
}

