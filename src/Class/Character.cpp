#include "Character.h"

#include <iostream>

Character::Character()
: coordinateXOfCharacter(Config::FIRST_POSITION_OF_CHARACTER)
, lanePtr(nullptr) {
    movementCD = 0;
    mIdleAnimation.setSpriteSheet(TextureHolder::get(TextureID::ZombieIdleAnim));
    mIdleAnimation.setRepeating(true);
    mIdleAnimation.setDuration(2);
    mIdleAnimation.setSpriteSheetGridSize({6, 5});
    mIdleAnimation.setNumFrames(30);
}

void Character::updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr, int direction,
                                          float dt) {
    if (movementCD > 0)
        return;
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
            if (coordinateXOfCharacter > (Config::WIDTH_OF_EACH_CELL / 2)) {
                coordinateXOfCharacter -= Config::WIDTH_OF_EACH_CELL;
            }
            break;
        }
        case MOVE_RIGHT: {
            if (coordinateXOfCharacter < Config::LAST_POSITION_OF_CHARACTER) {
                coordinateXOfCharacter += Config::WIDTH_OF_EACH_CELL;
            }
            break;
        }
        default:
            break;
    }
    movementCD = Config::TIME_MOVEMENT;
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

void Character::update(float dt) {
    movementCD -= dt;
    mIdleAnimation.update(dt);
}

void Character::draw() {
    float coordinateYOfCharacter = lanePtr->getCoordinateYOfLane() - HEIGHT_OF_CHARACTER_SPRITE * 2 / 3;
    float coordinateXOfCharacterInCell = Config::WIDTH_OF_EACH_CELL / 2
                                       + (coordinateXOfCharacter - Config::WIDTH_OF_CHARACTER / 2)
                                             / Config::WIDTH_OF_EACH_CELL
                                             * Config::WIDTH_OF_EACH_CELL
                                       - WIDTH_OF_CHARACTER_SPRITE / 2;

    mIdleAnimation.draw({coordinateXOfCharacterInCell, coordinateYOfCharacter},
                        {WIDTH_OF_CHARACTER_SPRITE, HEIGHT_OF_CHARACTER_SPRITE});
}
