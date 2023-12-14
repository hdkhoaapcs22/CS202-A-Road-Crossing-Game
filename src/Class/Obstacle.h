#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cstdlib>
#include <vector>

#include "raylib.h"

#include "../Config.h"
#include "../gui/GUIComponents/GUITexture.h"

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

    void draw(int coordinateYOfLane);

private:
    int coordinateXOfObstacles;
    ObstacleName obstacleName;

    GUITexture::Ptr mTexture;

private:
    void initializeGUI();
};

#endif
