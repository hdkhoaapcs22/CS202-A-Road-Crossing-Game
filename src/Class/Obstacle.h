#ifndef OBSTACLE_H
#define OBSTACLE_H

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

private:
    int coordinateXOfObstacles;
    ObstacleName obstacleName;
};

#endif
