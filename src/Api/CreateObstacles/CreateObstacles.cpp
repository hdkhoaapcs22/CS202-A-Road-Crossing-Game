#include "../Class/Obstacle.h"

Obstacle::Obstacle()
: coordinateXOfObstacles(0) {
}

Obstacle::Obstacle(const Obstacle& obstacle)
: coordinateXOfObstacles(obstacle.coordinateXOfObstacles)
, obstacleName(obstacle.obstacleName) {
}

Obstacle::ObstacleName Obstacle::randomObstacleName() {
    int randomObstacleName = rand() % 2;
    switch (randomObstacleName) {
        case 0:
            return ObstacleName::Rock;
        case 1:
            return ObstacleName::Tree;
    }
}

int Obstacle::randomCoordinateXOfObstacles() {
    int randomCoordinateXOfObstacles = rand() % CELL_IN_LANE;
    return randomCoordinateXOfObstacles;
}

Obstacle Obstacle::createObstacles() {
    Obstacle obstacle;
    obstacle.coordinateXOfObstacles = randomCoordinateXOfObstacles();
    obstacle.obstacleName = randomObstacleName();
    return obstacle;
}
