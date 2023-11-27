#include "Character.h"

#include <iostream>

Character::Character()
: coordinateXOfCharacter(FIRST_POSITION_OF_CHARACTER)
, lanePtr(nullptr) {
}

void Character::updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr, int direction,
                                          float dt) {
    switch (direction) {
        case MOVE_UP: {
            if (nextLanePtr != nullptr)
                lanePtr = nextLanePtr;
            break;
        }
        case MOVE_DOWN: {
            if (prevLanePtr != nullptr)
                lanePtr = prevLanePtr;
            break;
        }
        case MOVE_LEFT: {
            if (coordinateXOfCharacter > (WIDTH_OF_EACH_CELL / 2)) {
                coordinateXOfCharacter -= WIDTH_OF_EACH_CELL;
            }
            break;
        }
        case MOVE_RIGHT: {
            if (coordinateXOfCharacter < LAST_POSITION_OF_CHARACTER) {
                coordinateXOfCharacter += WIDTH_OF_EACH_CELL;
            }
            break;
        }
        default:
            break;
    }
}

void Character::assignLane(Lane* firstLane) {
    lanePtr = firstLane;
}

Lane* Character::getLanePtr() {
    return lanePtr;
}

int Character::getCoordinateX() const {
    return coordinateXOfCharacter;
}
