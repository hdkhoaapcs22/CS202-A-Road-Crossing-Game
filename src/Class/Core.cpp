#include "Core.h"

void Core::update(float dt) {
}

void Core::moveCharacter(int direction, float dt) {
    Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
    Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
    character.updateLocationOfCharacter(nextLanePtr, prevLanePtr, direction,
                                        dt);
}
