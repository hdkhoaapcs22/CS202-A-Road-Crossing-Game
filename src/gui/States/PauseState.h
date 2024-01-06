#ifndef SRC_GUI_STATES_PAUSESTATE_H
#define SRC_GUI_STATES_PAUSESTATE_H

#include "State.h"
#include "../../Class/Core.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"

#include "raylib.h"

class PauseState : public State {
public:
    PauseState(StateStack &stack, Context context);
    ~PauseState();

    bool update(float dt);
    void draw();
private:
    void initButtons();
private:
    GUITexture::Ptr mBackground;
    std::vector<Button::Ptr> mButtons;
};

#endif // SRC_GUI_STATES_PAUSESTATE_H
