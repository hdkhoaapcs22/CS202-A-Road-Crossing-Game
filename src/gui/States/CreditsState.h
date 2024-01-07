#ifndef SRC_GUI_STATES_CREDITSSTATE_H
#define SRC_GUI_STATES_CREDITSSTATE_H

#include "State.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"

#include "raylib.h"

class CreditsState : public State {
public:
    CreditsState(StateStack &stack, Context context);
    ~CreditsState();

    bool update(float dt);
    void draw();
private:
    void initButtons();
private:
    GUITexture::Ptr mBackground;
    GUITexture::Ptr mContent;
    std::vector<Button::Ptr> mButtons;
};

#endif // SRC_GUI_STATES_CREDITSSTATE_H
