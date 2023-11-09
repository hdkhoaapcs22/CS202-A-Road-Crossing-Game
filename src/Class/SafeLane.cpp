#include "SafeLane.h"

SafeLane::SafeLane() {
    int obstaclesNum = rand() % 5;
    for (int i = 0; i < obstaclesNum; ++i) {
        Obstacle* newObstacle = new Obstacle();
        while (checkOverlap(newObstacle->getCoordinateX()))
            newObstacle->randomCoordinateXOfObstacles();
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

bool SafeLane::checkOverlap(int x) {
    for (Obstacle* ptr : obstacles) {
        if (x == ptr->getCoordinateX()) {
            return true;
        }
    }
    return false;
}
