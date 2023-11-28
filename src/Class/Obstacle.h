#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cstdlib>
#include <vector>

#include "../Config.h"

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
    void setCoordinateX(int x);

private:
    int coordinateXOfObstacles;
    ObstacleName obstacleName;
};

#endif
