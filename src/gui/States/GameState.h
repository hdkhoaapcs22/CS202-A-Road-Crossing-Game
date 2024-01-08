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
    class GameInit : public BaseParameter {
    public:
        GameInit(bool resume, bool darkMode = false);
        bool isResume() const;
        bool isDarkMode() const;
    private:
        bool resume;
        bool darkMode;
    };

public:
    static const std::string PATH_TO_SAVE_FILE;;

public:
    GameState(StateStack &stack, Context context);
    ~GameState();

    bool update(float dt);
    void draw();

    void loadGame();
    static bool isResumable();

    void setParameter(BaseParameter::Ptr parameter) override;

private:
    Core::Ptr mCore;
    bool isLost{false};
    bool darkMode{false};
    std::vector<Button::Ptr> mButtons;

private:
    void initButtons();
};

#endif // SRC_GUI_STATES_GAMESTATE_H
