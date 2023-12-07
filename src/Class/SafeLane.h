#ifndef SAFELANE_H
#define SAFELANE_H

#include "Lane.h"
#include "Obstacle.h"

#include "../gui/GUIComponents/GUITexture.h"

class SafeLane : public Lane {
public:
    SafeLane(float coordinateYOfLane, bool hasObstacle = true);
    ~SafeLane();
    void update(float dt);
    void draw();
    bool checkOverlap(int x);

private:
    std::vector<Obstacle*> obstacles;

    GUITexture::Ptr mTexture;

private:
    void initializeGUI();
};

#endif
