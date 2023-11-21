#include "Core.h"
#include "SafeLane.h"
#include "RoadLane.h"

Core::Core() {
    score = 0;
    virtualScore = 0;
    character.assignLane(gameMap.getFirstLaneOfCharacter());
}

float Core::getSpeedMultiplier() {
    if (score < 93)
        return 1.0 * score * score / 7200 + 1.0 * score / 120 + 1;
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
        case Character::MOVE_UP: {
            Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
            if (nextLanePtr == nullptr || nextLanePtr->getLaneName() != Lane::LaneName::SafeLane)
                return false;
            return static_cast<SafeLane *>(nextLanePtr)->checkOverlap(coordinateXOfCharacterInCell);
        }
        case Character::MOVE_DOWN:{
            Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
            if (prevLanePtr == nullptr || prevLanePtr->getLaneName() != Lane::LaneName::SafeLane)
                return false;
            return static_cast<SafeLane *>(prevLanePtr)->checkOverlap(coordinateXOfCharacterInCell);
        }
        default:
            return false;
    }
}

void Core::update(float dt) {
    gameMap.update(dt, getSpeedMultiplier(), character.getLanePtr());
}

void Core::executeMovement(int direction, float dt) {
    if (detectBlockMovement(direction))
        return;
    moveCharacter(direction, dt);
    switch (direction) {
        case Character::MOVE_DOWN:
            --virtualScore;
            break;
        case Character::MOVE_UP:
            ++virtualScore;
            if (virtualScore > score)
                score = virtualScore;
            break;
        default:
            break;
    }
}

bool Core::isLost() {
    if (detectCollision())
        return true;
    if (character.getLanePtr() != gameMap.getFirstLane())
        return false;
    return gameMap.getFirstLane()->getCoordinateYOfLane() < 0;
}

void Core::moveCharacter(int direction, float dt) {
    Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
    Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
    character.updateLocationOfCharacter(nextLanePtr, prevLanePtr, direction, dt);
}
