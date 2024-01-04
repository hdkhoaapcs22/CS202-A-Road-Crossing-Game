#include "CountdownState.h"

CountdownState::CountdownState(StateStack& stack, Context context)
: State(stack, context) {
    mTimeElapsed = 0.0f;
    mCountdownSeconds = COUNTDOWN_SECONDS;
}

CountdownState::~CountdownState() {
}

bool CountdownState::update(float dt) {
    mTimeElapsed += dt;
    while (mTimeElapsed >= 1.0f) {
        mTimeElapsed -= 1.0f;
        mCountdownSeconds--;
    }
    if (mCountdownSeconds <= 0) {
        requestStackPop();
    }
    return false;
}

void CountdownState::draw() {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, 127});

    int maxSize = 100;
    int curSize = std::max(maxSize * easeBounceOut(mTimeElapsed, 0, 1, 1), 1.f);

    Vector2 textBound =
        MeasureTextEx(GetFontDefault(), std::to_string(mCountdownSeconds).c_str(), curSize, 1);
    float x = GetScreenWidth() / 2 - textBound.x / 2;
    float y = GetScreenHeight() / 2 - textBound.y / 2;

    DrawTextEx(FontHolder::get(FontID::Acme, curSize), std::to_string(mCountdownSeconds).c_str(), {x, y}, curSize, 1,
               WHITE);
}

float CountdownState::easeBounceOut(float time, float from, float change, float duration) {
    if ((time /= duration) < (1 / 2.75f)) {
        return change * (7.5625f * time * time) + from;
    } else if (time < (2 / 2.75f)) {
        return change * (7.5625f * (time -= (1.5f / 2.75f)) * time + 0.75f) + from;
    } else if (time < (2.5 / 2.75)) {
        return change * (7.5625f * (time -= (2.25f / 2.75f)) * time + 0.9375f) + from;
    } else {
        return change * (7.5625f * (time -= (2.625f / 2.75f)) * time + 0.984375f) + from;
    }
}
