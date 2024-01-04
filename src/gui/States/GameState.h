#ifndef SRC_GUI_STATES_GAMESTATE_H
#define SRC_GUI_STATES_GAMESTATE_H

#include "../../Class/Core.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"
#include "State.h"

#include "raylib.h"

class GameState : public State {
public:
    class ScoreData : public BaseParameter {
    public:
        ScoreData(int score);
        int getScore() const;

    private:
        int score;
    };

public:
    GameState(StateStack &stack, Context context);
    ~GameState();

    bool update(float dt);
    void draw();

private:
    Core mCore;
    bool isLost{false};
    std::vector<Button::Ptr> mButtons;

private:
    void initButtons();
};

#endif // SRC_GUI_STATES_GAMESTATE_H
