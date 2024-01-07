#ifndef SRC_GUI_STATES_SETTINGSSTATE_H
#define SRC_GUI_STATES_SETTINGSSTATE_H

#include "State.h"
#include "../../Class/Core.h"
#include "../GUIComponents/Button.h"
#include "../GUIComponents/GUITexture.h"
#include "../ResourceHolders/TextureHolder.h"

#include "raylib.h"

class SettingsState : public State {
public:
    static const std::string PATH_TO_SAVE_FILE;
public:
    SettingsState(StateStack &stack, Context context);
    ~SettingsState();

    bool update(float dt);
    void draw();

    static void loadData(Context context);
    static void saveData(Context context);

private:
    void initButtons();

private:
    GUITexture::Ptr mBackground, mContent;
    std::vector<Button::Ptr> mButtons;
};

#endif // SRC_GUI_STATES_SETTINGSSTATE_H
