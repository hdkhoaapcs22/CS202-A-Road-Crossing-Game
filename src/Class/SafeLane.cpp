#include "SafeLane.h"

SafeLane::SafeLane() {
    int obstaclesNum = rand()%5;
    for(int i = 0 ; i<obstaclesNum; ++i)
        obstacles.push_back(Obstacle());
}

void SafeLane::update(float dt) {
}
