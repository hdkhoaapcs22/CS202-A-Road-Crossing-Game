#ifndef Character_H
#define Character_H

#include "Lane.h"

class Character {
public:
    void moveCharacter(int direction, float dt);

private:
    int coordinateXOfCharacter;
    Lane* lanePtr;
};

#endif
