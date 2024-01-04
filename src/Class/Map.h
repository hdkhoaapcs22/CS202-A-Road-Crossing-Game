#ifndef MAP_H
#define MAP_H

#include <deque>
#include "../Config.h"
#include "Lane.h"

#include "raylib.h"

class Map {
public:
    Map();
    ~Map();
    static const int laneWidth = 14;

    void update(float dt, float speedMultiplier, Lane *characterLanePtr);
    void draw();

    Lane *getNextLane(Lane *curLanePtr);
    Lane *getPreviousLane(Lane *curLanePtr);
    Lane *getFirstLane();
    Lane *getFirstLaneOfCharacter();

    void setMoving(bool moving);

private:
    std::deque<Lane *> lanes;
    bool moving{true};

private:
    void moveLanes(float dt, float speedMultiplier, Lane *characterLanePtr);
    Lane *iteratorLanes(Lane *curLanePtr, const std::string &direction);
    void insertRoadLane(int numberOfSameLane);
    void insertSafeLane(int numberOfSameLane);
    void insertFireLane(int numberOfSameLane);
    void initializeGUI();
};

#endif