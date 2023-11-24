#ifndef STATES_HOMESTATE_H
#define STATES_HOMESTATE_H

#include "State.h"
#include "../../Class/Core.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"

#include "raylib.h"

class HomeState : public State {
public:
    HomeState(StateStack &stack, Context context);
    ~HomeState();

    bool update(float dt);
    void draw();

private:
    void initButtons();

private:
    GUITexture::Ptr mBackground;
    std::vector<Button::Ptr> mButtons;
};

#endif // STATES_HOMESTATE_H
