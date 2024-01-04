#ifndef SRC_GUI_STATES_GAMEOVERSTATE_H
#define SRC_GUI_STATES_GAMEOVERSTATE_H
#include "../../Class/Core.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"
#include "State.h"

#include "raylib.h"

class GameOverState : public State {
public:
    class ScoreData : public BaseParameter {
    public:
        ScoreData(int score);
        int getScore() const;

    private:
        int score;
    };

public:
    GameOverState(StateStack &stack, Context context);
    ~GameOverState();

    bool update(float dt);
    void draw();
    void setParameter(BaseParameter::Ptr parameter);

private:
    void initButtons();

private:
    GUITexture::Ptr mBackground;
    std::vector<Button::Ptr> mButtons;

    int score;
    int highScore;
};

#endif // SRC_GUI_STATES_GAMEOVERSTATE_H

