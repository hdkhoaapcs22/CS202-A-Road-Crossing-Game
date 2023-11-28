#ifndef SAFELANE_H
#define SAFELANE_H

#include "Lane.h"
#include "Obstacle.h"

class SafeLane : public Lane {
public:
    SafeLane(float coordinateYOfLane);
    ~SafeLane();
    void update(float dt);
    void draw();
    bool checkOverlap(int x);

private:
    std::vector<Obstacle*> obstacles;
};

#endif
