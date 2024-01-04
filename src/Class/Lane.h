#ifndef LANE_H
#define LANE_H

#include <fstream>
#include <iostream>

#include "../Config.h"

#include "raylib.h"

class Lane {
public:
    enum class LaneName {
        RoadLane,
        SafeLane,
        RiverLane,
        FireLane,
    };

    Lane();
    Lane(std::ifstream& input);
    Lane(float coordinateYOfLane);
    Lane(float coordinateYOfLane, LaneName laneName);

    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    float getCoordinateYOfLane() const;

    LaneName getLaneName();

    void move(float deltaY);
    virtual void save(std::ofstream& output);

private:
    float coordinateYOfLane;
    std::string saveID;
    LaneName laneName;
};

#endif
