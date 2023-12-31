#include "Core.h"
#include "RoadLane.h"
#include "SafeLane.h"

Core::Core() {
    initializeGUI();

    score = 0;
    virtualScore = 0;
    character.assignLane(gameMap.getLaneK(2));
    gameMap.setMoving(false);
}

Core::Core(std::ifstream &input) {
    initializeGUI();

    score = 0;
    virtualScore = 0;
    gameMap = Map(input);
    character = Character(input);
    int laneID, gameStateID;
    input >> laneID;
    character.assignLane(gameMap.getLaneK(laneID));
    input >> gameStateID;
    gameState = static_cast<GameState>(gameStateID);
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
    int leftHitbox = character.getCoordinateX() - Config::WIDTH_OF_CHARACTER / 2;
    int rightHitbox = character.getCoordinateX() + Config::WIDTH_OF_CHARACTER / 2;
    return static_cast<RoadLane *>(lanePtr)->checkCollision(leftHitbox, rightHitbox);
}

bool Core::detectBlockMovement(int direction) {
    int coordinateXOfCharacterInCell =
        (character.getCoordinateX() - Config::WIDTH_OF_CHARACTER / 2) / Config::WIDTH_OF_EACH_CELL;
    switch (direction) {
        case Character::MOVE_LEFT:
            if (character.getLanePtr()->getLaneName() != Lane::LaneName::SafeLane
                || coordinateXOfCharacterInCell == 0)
                return false;
            return static_cast<SafeLane *>(character.getLanePtr())
                ->checkOverlap(coordinateXOfCharacterInCell - 1);
        case Character::MOVE_RIGHT:
            if (character.getLanePtr()->getLaneName() != Lane::LaneName::SafeLane
                || coordinateXOfCharacterInCell == Config::CELL_IN_LANE - 1)
                return false;
            return static_cast<SafeLane *>(character.getLanePtr())
                ->checkOverlap(coordinateXOfCharacterInCell + 1);
        case Character::MOVE_UP: {
            Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
            if (nextLanePtr == nullptr || nextLanePtr->getLaneName() != Lane::LaneName::SafeLane)
                return false;
            return static_cast<SafeLane *>(nextLanePtr)->checkOverlap(coordinateXOfCharacterInCell);
        }
        case Character::MOVE_DOWN: {
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
    getInputs(dt);
    gameMap.update(dt, getSpeedMultiplier(), character.getLanePtr());
    character.update(dt);
    if (isLost()) {
        character.setDead();
        gameMap.setMoving(false);
        gameState = GameState::Lost;
    }
}

void Core::draw() {
    ClearBackground(BLACK);
    gameMap.draw();
    character.draw();
    drawScore();
}

void Core::executeMovement(int direction, float dt) {
    gameState = GameState::Playing;
    gameMap.setMoving(true);
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

void Core::getInputs(float dt) {
    if (gameState == GameState::Lost)
        return;
    if (IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP))
        executeMovement(Character::MOVE_UP, dt);
    else if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN))
        executeMovement(Character::MOVE_DOWN, dt);
    else if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT))
        executeMovement(Character::MOVE_LEFT, dt);
    else if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT))
        executeMovement(Character::MOVE_RIGHT, dt);
}

void Core::drawScore() {
    scoreFrame->draw();
    DrawTextEx(FontHolder::get(FontID::Acme, 48), std::to_string(score).c_str(), {130, 25}, 48, 0,
               WHITE);
}

void Core::initializeGUI() {
    scoreFrame = std::make_shared<GUITexture>();

    scoreFrame->setTexture(TextureHolder::get(TextureID::Score));
    scoreFrame->setPosition({15, 14});
}

bool Core::isLost() {
    if (detectCollision())
        return true;
    if (character.getLanePtr() != gameMap.getFirstLane())
        return false;
    return gameMap.getFirstLane()->getCoordinateYOfLane() >= Config::WINDOW_HEIGHT;
}

void Core::save(std::ofstream &output) {
    gameMap.save(output);
    character.save(output);
    output << gameMap.getLaneID(character.getLanePtr()) << " " << static_cast<int>(gameState)
           << std::endl;
}

void Core::moveCharacter(int direction, float dt) {
    Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
    Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
    character.updateLocationOfCharacter(nextLanePtr, prevLanePtr, direction, dt);
}
