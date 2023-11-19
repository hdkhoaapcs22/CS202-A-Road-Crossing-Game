#ifndef Character_H
#define Character_H

#include "Lane.h"

class Character {
public:
    static const int MOVE_UP = 1;
    static const int MOVE_DOWN = 2;
    static const int MOVE_LEFT = 3;
    static const int MOVE_RIGHT = 4;
    static const int WIDTH_OF_EACH_CELL = 78;
    static const int FIRST_POSITION_OF_CHARACTER = 507;
    static const int LAST_POSITION_OF_CHARACTER = 975;
    static const int HEIGHT_OF_CHARACTER = 50;
    static const int WIDTH_OF_CHARACTER = 40;
    static const float TIME_MOVEMENT;

public:
    Character();
    void assignLane(Lane* firstLane);
    void updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr,
                                   int direction, float dt);
    Lane* getLanePtr();
    int getCoordinateX() const;

private:
    int coordinateXOfCharacter;
    Lane* lanePtr;
};

#endif
