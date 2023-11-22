#ifndef CORE_H
#define CORE_H

#include "Character.h"
#include "Map.h"

class Core {
public:
    int getScreenSpeed();
    bool detectCollision();
    bool detectBlockMovement();
    void update(float dt);
    void moveCharacter(int direction, float dt);

private:
    int score;
    Map gameMap;
    Character character;
};

#endif
