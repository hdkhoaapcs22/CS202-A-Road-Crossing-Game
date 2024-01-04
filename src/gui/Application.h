#ifndef APPLICATION_H
#define APPLICATION_H

#include "ResourceHolders/MusicPlayer.h"
#include "ResourceHolders/FontHolder.h"
#include "ResourceHolders/TextureHolder.h"
#include "StateStack.h"

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    void update(float dt);
    void render();

    void registerStates();

    void loadTextures();
    void loadFonts();

private:
    StateStack mStateStack;

    MusicPlayer mMusic;
};

#endif // APPLICATION_H
