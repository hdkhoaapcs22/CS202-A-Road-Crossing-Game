#include "HomeState.h"

HomeState::HomeState(StateStack &stack, Context context)
: State(stack, context) {
}

HomeState::~HomeState() {
}

bool HomeState::update(float dt) {
    if (IsKeyPressed(KEY_W)) {
        mCore.moveCharacter(Character::MOVE_UP, dt);
    } else if (IsKeyPressed(KEY_S)) {
        mCore.moveCharacter(Character::MOVE_DOWN, dt);
    } else if (IsKeyPressed(KEY_A)) {
        mCore.moveCharacter(Character::MOVE_LEFT, dt);
    } else if (IsKeyPressed(KEY_D)) {
        mCore.moveCharacter(Character::MOVE_RIGHT, dt);
    }
    mCore.update(dt);
    return true;
}

void HomeState::draw() {
    ClearBackground(AppColor::BACKGROUND_1);
}
