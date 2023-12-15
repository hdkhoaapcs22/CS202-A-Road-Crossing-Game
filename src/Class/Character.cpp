#include "Character.h"

#include <iostream>

Character::Character()
: coordinateXOfCharacter(Config::FIRST_POSITION_OF_CHARACTER)
, lanePtr(nullptr)
, deltaPosition({0, 0}) {
    initializeGUI();
    movementCD = 0;
}

void Character::updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr, int direction,
                                          float dt) {
    if (movementCD > 0)
        return;
    if (isDead)
        return;
    Vector2 initialPosition = {coordinateXOfCharacter, lanePtr->getCoordinateYOfLane()};
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
    deltaPosition = {coordinateXOfCharacter - initialPosition.x,
                     lanePtr->getCoordinateYOfLane() - initialPosition.y};
    movementCD = Config::TIME_MOVEMENT;
}

void Character::assignLane(Lane* firstLane) {
    lanePtr = firstLane;
}

Lane* Character::getLanePtr() {
    return lanePtr;
}

float Character::getCoordinateX() const {
    return coordinateXOfCharacter;
}

void Character::prepareMovement(bool isPreparing) {
    isPreparingMovement = isPreparing;
}

void Character::setHorizontalFlipped(bool isFlipped) {
    mIdleAnimation.setHorizontalFlipped(isFlipped);
    mDeadAnimation.setHorizontalFlipped(isFlipped);
}

void Character::update(float dt) {
    movementCD -= dt;
    if (movementCD < 0)
        movementCD = 0;
    else {
        isPreparingMovement = false;
    }
    if (isDead)
        mDeadAnimation.update(dt);
    else
        mIdleAnimation.update(dt);
}

void Character::draw() {
    float jumpHeight = 20;
    Vector2 displayedPosition = {coordinateXOfCharacter - WIDTH_OF_CHARACTER_SPRITE / 2
                                     - deltaPosition.x * movementCD / Config::TIME_MOVEMENT,
                                 lanePtr->getCoordinateYOfLane()
                                     - HEIGHT_OF_CHARACTER_SPRITE * 3 / 4
                                     + 4 * jumpHeight * (movementCD / Config::TIME_MOVEMENT) * (movementCD / Config::TIME_MOVEMENT) - 4 * jumpHeight * (movementCD / Config::TIME_MOVEMENT)};

    if (isDead)
        mDeadAnimation.draw(displayedPosition,
                            {WIDTH_OF_CHARACTER_SPRITE, HEIGHT_OF_CHARACTER_SPRITE});
    else {
        Vector2 sizeOfCharacter = {WIDTH_OF_CHARACTER_SPRITE, HEIGHT_OF_CHARACTER_SPRITE};
        if (isPreparingMovement) {
            displayedPosition.y += sizeOfCharacter.y / 4;
            sizeOfCharacter.y -= sizeOfCharacter.y / 4;
        }
        mIdleAnimation.draw(displayedPosition, sizeOfCharacter);
    }
}

void Character::setDead() {
    isDead = true;
}

void Character::initializeGUI() {
    mIdleAnimation.setSpriteSheet(TextureHolder::get(TextureID::ZombieIdleAnim));
    mIdleAnimation.setRepeating(true);
    mIdleAnimation.setDuration(2);
    mIdleAnimation.setSpriteSheetGridSize({6, 5});
    mIdleAnimation.setNumFrames(30);

    mDeadAnimation.setSpriteSheet(TextureHolder::get(TextureID::ZombieDeadAnim));
    mDeadAnimation.setRepeating(false);
    mDeadAnimation.setDuration(DEAD_ANIMATION_TIME);
    mDeadAnimation.setSpriteSheetGridSize({6, 5});
    mDeadAnimation.setNumFrames(30);
}
