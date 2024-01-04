#ifndef FIRELANE_H
#define FIRELANE_H

#include "Lane.h"

#include "../gui/GUIComponents/GUITexture.h"

class FireLane : public Lane {
public:
    FireLane(float coordinateYOfLane);
    ~FireLane();
    void update(float dt);
    void draw();

private:
    bool isFire;
    float fireTime;
    float fireTimer;
    float fireDuration;
    GUITexture::Ptr mTexture;

private:
    void initializeGUI();
    float randomFireTime();
};

#endif
