#ifndef MAP_H
#define MAP_H

#include <deque>
#include "Lane.h"
#include "../Config.h"

class Map {
public:
    Map();
    ~Map();
    static const int NUMBER_OF_LANES = 10;
    static const int SIZE_OF_A_LANE = Config::WINDOW_WIDTH / NUMBER_OF_LANES;
    static const int laneWidth = 14;
    static const int baseSpeed = 100;
    void update(float dt, double speedMultiplier);
    Lane *getNextLane(Lane *curLanePtr);
    Lane *getPreviousLane(Lane *curLanePtr);
    Lane *getFirstLane();
    Lane *getFirstLaneOfCharacter();

private:
    std::deque<Lane *> lanes;
    void moveLanes(float dt, double speedMultiplier);
    Lane *iteratorLanes(Lane *curLanePtr, const std::string &direction);
    void insertRoadLane(int numberOfSameLane);
    void insertSafeLane(int numberOfSameLane);
    // void insertRiverLane();
};

#endif