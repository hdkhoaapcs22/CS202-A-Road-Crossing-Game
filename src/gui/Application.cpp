#include "Application.h"
#include "../Config.h"
#include "ResourceHolders/ResourceIdentifiers.h"
#include "States/HomeState.h"
#include "States/SettingsState.h"
#include "States/CreditsState.h"
#include "States/GameState.h"
#include "States/StateIdentifiers.h"

#include <iostream>

Application::Application()
: mStateStack(State::Context()) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);

    InitWindow(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, "RoadCrossing");
    SetTargetFPS(Config::FPS);

    loadTextures();
    loadFonts();

    // SetWindowIcon(LoadImageFromTexture(
    //     TextureHolder::get(TextureID::IconLogo)));

    registerStates();
    mStateStack.pushState(StateIDs::Game);
}

Application::~Application() {
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
}

void Application::loadTextures() {
    std::string BASE_PATH = "asset/texture/";
    TextureHolder::load(TextureID::ZombieIdleAnim,
                        BASE_PATH + "ZombieIdleAnim.png");
    TextureHolder::load(TextureID::ZombieDeadAnim,
                        BASE_PATH + "ZombieDeadAnim.png");
    TextureHolder::load(TextureID::MenuBackground,
                        BASE_PATH + "MenuBackground.png");
    TextureHolder::load(TextureID::MenuPlayButton,
                        BASE_PATH + "MenuPlayButton.png");
    TextureHolder::load(TextureID::MenuSettingsButton,
                        BASE_PATH + "MenuSettingsButton.png");
    TextureHolder::load(TextureID::MenuCreditsButton,
                        BASE_PATH + "MenuCreditsButton.png");
    TextureHolder::load(TextureID::PopUpMenu, BASE_PATH + "PopUpMenu.png");
    TextureHolder::load(TextureID::PopUpCloseButton,
                        BASE_PATH + "PopUpCloseButton.png");
    TextureHolder::load(TextureID::SafeLane, BASE_PATH + "SafeLane.png");
    TextureHolder::load(TextureID::Score, BASE_PATH + "Score.png");
}

void Application::loadFonts() {
    std::string BASE_PATH = "asset/font/";
    FontHolder::load(FontID::Acme, BASE_PATH + "Acme.ttf");
}
