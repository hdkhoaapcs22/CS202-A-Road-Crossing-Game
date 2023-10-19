#include "HomeState.h"

#include "raylib.h"

HomeState::HomeState(StateStack &stack, Context context)
: State(stack, context) {
}

HomeState::~HomeState() {
}

bool HomeState::update(float dt) {
    return true;
}

void HomeState::draw() {
    ClearBackground(AppColor::BACKGROUND_1);
}
