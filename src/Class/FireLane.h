#ifndef FIRELANE_H
#define FIRELANE_H

#include <fstream>
#include "Lane.h"

#include "../gui/GUIComponents/GUITexture.h"
#include "../gui/Animation.h"

class FireLane : public Lane {
public:
    static constexpr float CHARGE_TIME = 2.0;
public:
    FireLane(float coordinateYOfLane);
    FireLane(std::ifstream& input);
    ~FireLane();
    void save(std::ofstream& output) override;

    void update(float dt);
    void draw();

    bool isOnFire() const;

private:
    bool isFire;
    float fireTime;
    float fireTimer;
    float fireDuration;
    Animation mObject;
    std::vector<Animation> mAnimations;

private:
    void initializeGUI();
    float randomFireTime();
};

#endif
