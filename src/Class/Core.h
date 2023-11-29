#ifndef CORE_H
#define CORE_H

#include "Character.h"
#include "Map.h"

class Core {
public:
    enum class GameState {
        WaitingToStart,
        Playing,
        Lost
    };
public:
    Core();
    float getSpeedMultiplier();
    bool detectCollision();
    bool detectBlockMovement(int direction);

    void update(float dt);
    void draw();

    bool isLost();

private:
    int score;
    int virtualScore;
    Map gameMap;
    Character character;

    GameState gameState{GameState::WaitingToStart};

private:
    void moveCharacter(int direction, float dt);
    void executeMovement(int direction, float dt);
    void getInputs(float dt);
};

#endif
