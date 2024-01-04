#ifndef FIRELANE_H
#define FIRELANE_H

#include <fstream>
#include "Lane.h"

#include "../gui/GUIComponents/GUITexture.h"

class FireLane : public Lane {
public:
    FireLane(float coordinateYOfLane);
    FireLane(std::ifstream& input);
    ~FireLane();

    void update(float dt);
    void draw();
    void save(std::ofstream& output) override;

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
