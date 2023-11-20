#ifndef CORE_H
#define CORE_H

#include "Character.h"
#include "Map.h"

class Core {
public:
    Core();
    double getSpeedMultiplier();
    bool detectCollision();
    bool detectBlockMovement(int direction);
    void update(float dt);
    void executeMovement(int direction, float dt);
    bool isLost();

private:
    int score;
    int virtualScore;
    Map gameMap;
    Character character;
    void moveCharacter(int direction, float dt);
};

#endif
