#ifndef Character_H
#define Character_H

#include "Lane.h"

class Character {
public:
    static const int MOVE_UP = 1;
    static const int MOVE_DOWN = 2;
    static const int MOVE_LEFT = 3;
    static const int MOVE_RIGHT = 4;

public:
    void moveCharacter(int direction, float dt);

private:
    int coordinateXOfCharacter;
    Lane* lanePtr;
};

#endif
