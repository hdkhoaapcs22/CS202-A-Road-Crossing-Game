#include "Core.h"
#include "SafeLane.h"
#include "RoadLane.h"

Core::Core() {
    score = 0;
    character.assignLane(gameMap.getFirstLaneOfCharacter());
}

double Core::getSpeedMultiplier() {
    if (score < 93)
        return 1.0 / 7200 * score * score + 1.0 / 120 * score + 1;
    return 3;
}

bool Core::detectCollision() {
    Lane *lanePtr = character.getLanePtr();
    if (lanePtr->getLaneName() != Lane::LaneName::RoadLane)
        return false;
    int leftHitbox = character.getCoordinateX() - Character::WIDTH_OF_CHARACTER / 2;
    int rightHitbox = character.getCoordinateX() + Character::WIDTH_OF_CHARACTER / 2;
    return static_cast<RoadLane *>(lanePtr)->checkCollision(leftHitbox, rightHitbox);
}

bool Core::detectBlockMovement(int direction) {
    int coordinateXOfCharacterInCell =
        (character.getCoordinateX() - Character::WIDTH_OF_CHARACTER / 2)
        / Character::WIDTH_OF_EACH_CELL;
    switch (direction) {
        case Character::MOVE_LEFT:
            if (character.getLanePtr()->getLaneName() != Lane::LaneName::SafeLane
                || coordinateXOfCharacterInCell == 0)
                return false;
            return static_cast<SafeLane *>(character.getLanePtr())
                ->checkOverlap(coordinateXOfCharacterInCell - 1);
        case Character::MOVE_RIGHT:
            if (character.getLanePtr()->getLaneName() != Lane::LaneName::SafeLane
                || coordinateXOfCharacterInCell == Lane::CELL_IN_LANE - 1)
                return false;
            return static_cast<SafeLane *>(character.getLanePtr())
                ->checkOverlap(coordinateXOfCharacterInCell + 1);
        case Character::MOVE_UP:
            Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
            if (nextLanePtr == nullptr || nextLanePtr->getLaneName() != Lane::LaneName::SafeLane)
                return false;
            return static_cast<SafeLane *>(nextLanePtr)->checkOverlap(coordinateXOfCharacterInCell);
        default:
            Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
            if (prevLanePtr == nullptr || prevLanePtr->getLaneName() != Lane::LaneName::SafeLane)
                return false;
            return static_cast<SafeLane *>(prevLanePtr)->checkOverlap(coordinateXOfCharacterInCell);
    }
}

void Core::update(float dt) {
    gameMap.update(dt, getSpeedMultiplier());
}

void Core::executeMovement(int direction, float dt) {
    if (detectBlockMovement(direction))
        return;
    moveCharacter(direction, dt);
    if (direction == Character::MOVE_UP)
        ++score;
}

bool Core::isLose() {
    if (detectCollision())
        return true;
    if (character.getLanePtr() != gameMap.getFirstLane())
        return false;
    int lowerBound = gameMap.getFirstLane()->getCoordinateYOfLane() + Map::sizeOfALane
                   - Character::HEIGHT_OF_CHARACTER;
    return lowerBound < 0;
}

void Core::moveCharacter(int direction, float dt) {
    Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
    Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
    character.updateLocationOfCharacter(nextLanePtr, prevLanePtr, direction, dt);
}
