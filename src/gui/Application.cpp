#include "Application.h"
#include "../Config.h"
#include "ResourceHolders/ResourceIdentifiers.h"
#include "States/CreditsState.h"
#include "States/GameOverState.h"
#include "States/GameState.h"
#include "States/HomeState.h"
#include "States/SettingsState.h"
#include "States/PauseState.h"
#include "States/CountdownState.h"
#include "States/StateIdentifiers.h"

#include <iostream>

Application::Application()
: mStateStack(State::Context(mMusic)) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);

    InitWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, "RoadCrossing");
    SetTargetFPS(Config::FPS);
    InitAudioDevice();

    loadTextures();
    loadFonts();

    // SetWindowIcon(LoadImageFromTexture(
    //     TextureHolder::get(TextureID::IconLogo)));

    registerStates();
    mStateStack.pushState(StateIDs::Home);
}

Application::~Application() {
    CloseAudioDevice();
    CloseWindow();
}

void Application::run() {
    while (!WindowShouldClose()) {
        update(GetFrameTime());
        render();
    }
}

void Application::update(float dt) {
    mStateStack.update(dt);
}

void Application::render() {
    BeginDrawing();
    mStateStack.draw();
    EndDrawing();
}

void Application::registerStates() {
    mStateStack.registerState<HomeState>(StateIDs::Home);
    mStateStack.registerState<SettingsState>(StateIDs::Settings);
    mStateStack.registerState<CreditsState>(StateIDs::Credits);
    mStateStack.registerState<GameState>(StateIDs::Game);
    mStateStack.registerState<GameOverState>(StateIDs::GameOver);
    mStateStack.registerState<PauseState>(StateIDs::Pause);
    mStateStack.registerState<CountdownState>(StateIDs::Countdown);
}

void Application::loadTextures() {
    std::string BASE_PATH = "asset/texture/";
    TextureHolder::load(TextureID::ZombieIdleAnim, BASE_PATH + "ZombieIdleAnim.png");
    TextureHolder::load(TextureID::ZombieDeadAnim, BASE_PATH + "ZombieDeadAnim.png");
    TextureHolder::load(TextureID::MenuBackground, BASE_PATH + "MenuBackground.png");
    TextureHolder::load(TextureID::MenuPlayButton, BASE_PATH + "MenuPlayButton.png");
    TextureHolder::load(TextureID::MenuSettingsButton, BASE_PATH + "MenuSettingsButton.png");
    TextureHolder::load(TextureID::MenuCreditsButton, BASE_PATH + "MenuCreditsButton.png");
    TextureHolder::load(TextureID::PopUpMenu, BASE_PATH + "PopUpMenu.png");
    TextureHolder::load(TextureID::PopUpCloseButton, BASE_PATH + "PopUpCloseButton.png");
    TextureHolder::load(TextureID::SafeLane, BASE_PATH + "SafeLane.png");
    TextureHolder::load(TextureID::RoadLane, BASE_PATH + "RoadLane.png");
    TextureHolder::load(TextureID::Score, BASE_PATH + "Score.png");
    TextureHolder::load(TextureID::GameOver, BASE_PATH + "GameOver.png");
    TextureHolder::load(TextureID::HomeButton, BASE_PATH + "HomeButton.png");
    TextureHolder::load(TextureID::RetryButton, BASE_PATH + "RetryButton.png");
    TextureHolder::load(TextureID::ResumeButton, BASE_PATH + "ResumeButton.png");
    TextureHolder::load(TextureID::PauseButton, BASE_PATH + "PauseButton.png");
    TextureHolder::load(TextureID::ObstacleType1, BASE_PATH + "ObstacleType1.png");
    TextureHolder::load(TextureID::ObstacleType2, BASE_PATH + "ObstacleType2.png");
    TextureHolder::load(TextureID::TrafficLightAnim, BASE_PATH + "TrafficLightAnim.png");
    TextureHolder::load(TextureID::Stoppable1, BASE_PATH + "Stoppable1.png");
    TextureHolder::load(TextureID::Stoppable2, BASE_PATH + "Stoppable2.png");
    TextureHolder::load(TextureID::Stoppable3, BASE_PATH + "Stoppable3.png");
    TextureHolder::load(TextureID::Stoppable4, BASE_PATH + "Stoppable4.png");
    TextureHolder::load(TextureID::Stoppable5, BASE_PATH + "Stoppable5.png");
    TextureHolder::load(TextureID::Unstoppable1, BASE_PATH + "Unstoppable1.png");
    TextureHolder::load(TextureID::Unstoppable2, BASE_PATH + "Unstoppable2.png");
    TextureHolder::load(TextureID::Unstoppable3, BASE_PATH + "Unstoppable3.png");
    TextureHolder::load(TextureID::Unstoppable4, BASE_PATH + "Unstoppable4.png");
    TextureHolder::load(TextureID::Unstoppable5, BASE_PATH + "Unstoppable5.png");
    TextureHolder::load(TextureID::SettingsTexture, BASE_PATH + "SettingsTexture.png");
    TextureHolder::load(TextureID::LeftButton, BASE_PATH + "LeftButton.png");
    TextureHolder::load(TextureID::RightButton, BASE_PATH + "RightButton.png");
    TextureHolder::load(TextureID::SmallPopUpMenu, BASE_PATH + "SmallPopUpMenu.png");
    TextureHolder::load(TextureID::MenuNewGameButton, BASE_PATH + "MenuNewGameButton.png");
    TextureHolder::load(TextureID::MenuContinueButton, BASE_PATH + "MenuContinueButton.png");
    TextureHolder::load(TextureID::MenuGoBackButton, BASE_PATH + "MenuGoBackButton.png");
    TextureHolder::load(TextureID::FireObjectAnim, BASE_PATH + "FireObjectAnim.png");
    TextureHolder::load(TextureID::FirePatternAnim, BASE_PATH + "FirePatternAnim.png");
}

void Application::loadFonts() {
    std::string BASE_PATH = "asset/font/";
    FontHolder::load(FontID::Acme, BASE_PATH + "Acme.ttf");
}
