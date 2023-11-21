#include "HomeState.h"

HomeState::HomeState(StateStack &stack, Context context)
: State(stack, context) {
}

HomeState::~HomeState() {
}

bool HomeState::update(float dt) {
    if (IsKeyPressed(KEY_W)) {
        mCore.executeMovement(Character::MOVE_UP, dt);
    } else if (IsKeyPressed(KEY_S)) {
        mCore.executeMovement(Character::MOVE_DOWN, dt);
    } else if (IsKeyPressed(KEY_A)) {
        mCore.executeMovement(Character::MOVE_LEFT, dt);
    } else if (IsKeyPressed(KEY_D)) {
        mCore.executeMovement(Character::MOVE_RIGHT, dt);
    }
    mCore.update(dt);
    return true;
}

void HomeState::draw() {
    ClearBackground(AppColor::BACKGROUND_1);
}
