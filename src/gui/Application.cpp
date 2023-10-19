#include "Application.h"
#include "ResourceHolders/ResourceIdentifiers.h"
#include "States/HomeState.h"
#include "States/StateIdentifiers.h"

#include <iostream>

Application::Application()
: mStateStack(State::Context()) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RoadCrossing");
    SetTargetFPS(FPS);

    loadTextures();
    loadFonts();

    // SetWindowIcon(LoadImageFromTexture(
    //     TextureHolder::getInstance().get(TextureID::IconLogo)));

    registerStates();
    mStateStack.pushState(StateIDs::Home);
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
}

void Application::loadTextures() {
    // std::string BASE_PATH = "asset/texture/";
    // TextureHolder::getInstance().load(TextureID::DefinitionSwitch,
    //                                   BASE_PATH + "DefinitionSwitch.png");
}

void Application::loadFonts() {
    // std::string BASE_PATH = "asset/font/";
    // FontHolder::getInstance().load(FontID::Inter, BASE_PATH + "Inter.ttf");
}
