#ifndef SAFELANE_H
#define SAFELANE_H

#include "Lane.h"
#include "Obstacle.h"

class SafeLane : public Lane{
public:
    SafeLane();
    void update(float dt);
private:
    std::vector<Obstacle> obstacles;
};

#endif