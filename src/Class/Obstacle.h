#ifndef OBSTACLE_H
#define OBSTACLE_H

#define CELL_IN_LANE 13
#include <cstdlib>
#include <vector>

class Obstacle {
public:
    enum class ObstacleName {
        Rock,
        Tree
    };
    Obstacle();
    ObstacleName randomObstacleName();
    int randomCoordinateXOfObstacles();
    Obstacle createObstacles();

private:
    int coordinateXOfObstacles;
    ObstacleName obstacleName;
};

#endif
