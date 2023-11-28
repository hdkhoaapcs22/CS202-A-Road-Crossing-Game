#ifndef Character_H
#define Character_H

#include "Lane.h"
#include "../Config.h"

#include "raylib.h"
class Character {
public:
    static const int MOVE_UP = 1;
    static const int MOVE_DOWN = 2;
    static const int MOVE_LEFT = 3;
    static const int MOVE_RIGHT = 4;
public:
    Character();
    void assignLane(Lane* firstLane);
    void updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr,
                                   int direction, float dt);
    Lane* getLanePtr();
    int getCoordinateX() const;

    void update(float dt);
    void draw();

private:
    int coordinateXOfCharacter;
    Lane* lanePtr;
    float movementCD;
};

#endif
