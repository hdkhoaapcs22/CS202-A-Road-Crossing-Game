#include "SafeLane.h"

SafeLane::SafeLane(float coordinateYOfLane)
: Lane(coordinateYOfLane, Lane::LaneName::SafeLane) {
    int obstaclesNum = rand() % 5;
    for (int i = 0; i < obstaclesNum; ++i) {
        Obstacle* newObstacle = new Obstacle();
        while (checkOverlap(newObstacle->getCoordinateX())) {
            newObstacle->setCoordinateX(newObstacle->randomCoordinateXOfObstacles());
        }
        obstacles.push_back(newObstacle);
    }
}

SafeLane::~SafeLane() {
    for (Obstacle*& ptr : obstacles) {
        delete ptr;
        ptr = nullptr;
    }
}

void SafeLane::update(float dt) {
}

void SafeLane::draw() {
}

bool SafeLane::checkOverlap(int x) {
    for (Obstacle* ptr : obstacles) {
        if (x == ptr->getCoordinateX()) {
            return true;
        }
    }
    return false;
}
