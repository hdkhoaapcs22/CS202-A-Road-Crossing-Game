#ifndef SRC_GUI_STATES_COUNTDOWNSTATE_H
#define SRC_GUI_STATES_COUNTDOWNSTATE_H

#include "../ResourceHolders/FontHolder.h"
#include "State.h"

#include "raylib.h"

class CountdownState : public State {
public:
    constexpr static int COUNTDOWN_SECONDS = 3;

public:
    CountdownState(StateStack &stack, Context context);
    ~CountdownState();

    bool update(float dt);
    void draw();

private:
    float mTimeElapsed;
    int mCountdownSeconds;

private:
    float easeBounceOut(float t, float b, float c, float d);
};

#endif // SRC_GUI_STATES_COUNTDOWNSTATE_H
