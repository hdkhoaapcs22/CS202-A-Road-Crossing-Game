#ifndef Character_H
#define Character_H

#include <fstream>
#include "../Config.h"
#include "../gui/Animation.h"
#include "../gui/ResourceHolders/TextureHolder.h"
#include "Lane.h"

#include "raylib.h"

class Character {
public:
    static const int MOVE_UP = 1;
    static const int MOVE_DOWN = 2;
    static const int MOVE_LEFT = 3;
    static const int MOVE_RIGHT = 4;

    static const int WIDTH_OF_CHARACTER_SPRITE = 100;
    static const int HEIGHT_OF_CHARACTER_SPRITE = 150;

    static constexpr float DEAD_ANIMATION_TIME = 2.0f;

public:
    Character();
    Character(std::ifstream& input);
    void save(std::ofstream& output);
    void assignLane(Lane* firstLane);
    void updateLocationOfCharacter(Lane* nextLanePtr, Lane* prevLanePtr, int direction, float dt);
    Lane* getLanePtr();
    float getCoordinateX() const;

    void prepareMovement(bool isPreparing);
    void setHorizontalFlipped(bool isFlipped);

    void update(float dt);
    void draw();

    void setDead();

    void initializeGUI();

private:
    Vector2 deltaPosition;
    float coordinateXOfCharacter;
    Lane* lanePtr;
    float movementCD;
    Animation mIdleAnimation;
    Animation mDeadAnimation;

    bool isDead{false};
    bool isPreparingMovement{false};
};

#endif
