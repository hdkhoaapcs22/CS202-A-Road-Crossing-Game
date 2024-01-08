#include "Core.h"
#include "FireLane.h"
#include "RoadLane.h"
#include "SafeLane.h"

Core::Core() {
    initializeGUI();

    score = 0;
    virtualScore = 0;
    character.assignLane(gameMap.getLaneK(2));
    gameMap.setMoving(false);
}

Core::Core(std::ifstream &input)
: gameMap(input)
, character(input) {
    input >> darkMode;
    setDarkMode(darkMode);

    initializeGUI();

    score = 0;
    virtualScore = 0;
    input >> score >> virtualScore;
    int laneID, gameStateID;
    input >> laneID;
    character.assignLane(gameMap.getLaneK(laneID));
    input >> gameStateID;
    gameState = static_cast<GameState>(gameStateID);
}

Core::~Core() {
}

float Core::getSpeedMultiplier() {
    if (score < 93)
        return 1.0 * score * score / 7200 + 1.0 * score / 120 + 1;
    return 3;
}

bool Core::detectCollision() {
    Lane *lanePtr = character.getLanePtr();
    if (lanePtr->getLaneName() == Lane::LaneName::RoadLane) {
        int leftHitbox = character.getCoordinateX() - Config::WIDTH_OF_CHARACTER / 2;
        int rightHitbox = character.getCoordinateX() + Config::WIDTH_OF_CHARACTER / 2;
        return static_cast<RoadLane *>(lanePtr)->checkCollision(leftHitbox, rightHitbox);
    } else if (lanePtr->getLaneName() == Lane::LaneName::FireLane) {
        return static_cast<FireLane *>(lanePtr)->isOnFire();
    }
    return false;
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
    gameMap.drawUpper(character.getLanePtr());
    character.draw();
    gameMap.drawLower(character.getLanePtr());
    if (darkMode)
        drawDarkMode();
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
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)
        || IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        character.prepareMovement(true);
    } else {
        character.prepareMovement(false);
    }
    if (IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP))
        executeMovement(Character::MOVE_UP, dt);
    else if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN))
        executeMovement(Character::MOVE_DOWN, dt);
    else if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) {
        character.setHorizontalFlipped(false);
        executeMovement(Character::MOVE_LEFT, dt);
    } else if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) {
        character.setHorizontalFlipped(true);
        executeMovement(Character::MOVE_RIGHT, dt);
    }
}

void Core::drawDarkMode() {
    float positionX = character.getCoordinateX() - darkCover->getTexture().width / 2;
    float positionY = character.getLanePtr()->getCoordinateYOfLane()
        - darkCover->getTexture().height / 2;
    darkCover->setPosition({positionX, positionY});
    darkCover->draw();
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
    return gameMap.getFirstLane()->getCoordinateYOfLane()
        >= Config::WINDOW_HEIGHT + Config::SIZE_OF_A_LANE / 2;
}

int Core::getScore() const {
    return score;
}

void Core::setDarkMode(bool darkMode) {
    this->darkMode = darkMode;
    if (darkMode) {
        darkCover = std::make_shared<GUITexture>();
        darkCover->setTexture(TextureHolder::get(TextureID::DarkCover));
    }
}

void Core::save(std::ofstream &output) {
    gameMap.save(output);
    character.save(output);
    output << darkMode << std::endl;
    output << score << " " << virtualScore << " ";
    output << gameMap.getLaneID(character.getLanePtr()) << " " << static_cast<int>(gameState)
           << std::endl;
}

void Core::moveCharacter(int direction, float dt) {
    Lane *nextLanePtr = gameMap.getNextLane(character.getLanePtr());
    Lane *prevLanePtr = gameMap.getPreviousLane(character.getLanePtr());
    character.updateLocationOfCharacter(nextLanePtr, prevLanePtr, direction, dt);
}
