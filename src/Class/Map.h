#ifndef MAP_H
#define MAP_H

#include <deque>
#include "Lane.h"

class Map {
public:
    static const int numberOfLanes = 10;
    static const int laneWidth = 14;
    void update(float dt);

private:
    std::deque<Lane*> lanes;
    void moveLanes(float dt);
};

#endif
