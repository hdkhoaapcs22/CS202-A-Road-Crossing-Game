#include "Obstacle.h"
#include "Lane.h"

Obstacle::Obstacle()
: coordinateXOfObstacles(randomCoordinateXOfObstacles())
, obstacleName(randomObstacleName()) {
}

Obstacle::ObstacleName Obstacle::randomObstacleName() {
    int randomName = rand() % 2;
    if (randomName == 0) {
        return ObstacleName::Rock;
    }
    return ObstacleName::Tree;
}

int Obstacle::randomCoordinateXOfObstacles() {
    int randomCoordinateXOfObstacles = rand() % Config::CELL_IN_LANE;
    return randomCoordinateXOfObstacles;
}

int Obstacle::getCoordinateX() const {
    return coordinateXOfObstacles;
}

void Obstacle::setCoordinateX(int x) {
    coordinateXOfObstacles = x;
}
