#ifndef ROAD_LANE_H
#define ROAD_LANE_H

#include <deque>
#include "Enemy.h"
#include "Lane.h"

class RoadLane : public Lane {
public:
    RoadLane();
    void manageTraffic(float dt);
    void checkHasTrafficLight();
    int randomDirection();
    void update(float dt) override;

private:
    static const int BREAK_TIME = 3;
    bool hasTrafficLight;
    bool isRedSignal;
    int breakTimer;
    int enemyID;
    std::deque<Enemy*> enemies;
};

#endif
