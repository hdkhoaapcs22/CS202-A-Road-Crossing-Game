#ifndef STATES_HOMESTATE_H
#define STATES_HOMESTATE_H

#include "State.h"
#include "../../Class/Core.h"

#include "raylib.h"

class HomeState : public State {
public:
    HomeState(StateStack &stack, Context context);
    ~HomeState();

    bool update(float dt);
    void draw();

private:
    Core mCore;
};

#endif // STATES_HOMESTATE_H