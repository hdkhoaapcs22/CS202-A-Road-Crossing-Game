#ifndef Character_H
#define Character_H

#include "Lane.h"
#include "../Config.h"
#include "../gui/Animation.h"
#include "../gui/ResourceHolders/TextureHolder.h"

#include "raylib.h"
class Character {
public:
    static const int MOVE_UP = 1;
    static const int MOVE_DOWN = 2;
    static const int MOVE_LEFT = 3;
    static const int MOVE_RIGHT = 4;

    static const int WIDTH_OF_CHARACTER_SPRITE = 100;
    static const int HEIGHT_OF_CHARACTER_SPRITE = 150;

public:
    Character();
    void assignLane(Lane* firstLane);
    void updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr,
                                   int direction, float dt);
    Lane* getLanePtr();
    float getCoordinateX() const;

    void update(float dt);
    void draw();

    void setDead();
private:
    Vector2 deltaPosition;
    float coordinateXOfCharacter;
    Lane* lanePtr;
    float movementCD;
    Animation mIdleAnimation;

    bool isDead{false};
};

#endif
