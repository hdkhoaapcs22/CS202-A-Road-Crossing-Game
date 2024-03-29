#ifndef FIRELANE_H
#define FIRELANE_H

#include <fstream>
#include "Lane.h"

#include "../gui/GUIComponents/GUITexture.h"
#include "../gui/Animation.h"

class FireLane : public Lane {
public:
    static constexpr float CHARGE_TIME = 1.5;
public:
    FireLane(float coordinateYOfLane, Biome biome = Biome::None);
    FireLane(std::ifstream& input, Biome biome = Biome::None);
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

    GUITexture::Ptr mTexture;

private:
    void initializeGUI();
    float randomFireTime();
};

#endif
