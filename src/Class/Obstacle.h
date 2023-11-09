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
    int getCoordinateX() const;

private:
    int coordinateXOfObstacles;
    ObstacleName obstacleName;
};

#endif
