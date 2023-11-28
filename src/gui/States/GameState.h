#ifndef SRC_GUI_STATES_GAMESTATE_H
#define SRC_GUI_STATES_GAMESTATE_H

#include "State.h"
#include "../../Class/Core.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"

#include "raylib.h"

class GameState : public State {
public:
    GameState(StateStack &stack, Context context);
    ~GameState();

    bool update(float dt);
    void draw();
private:
    Core mCore;
};

#endif // SRC_GUI_STATES_GAMESTATE_H
