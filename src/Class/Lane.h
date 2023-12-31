#ifndef LANE_H
#define LANE_H

#include <fstream>
#include "../Config.h"

#include "raylib.h"

class Lane {
public:
    enum class LaneName {
        RoadLane,
        SafeLane,
        FireLane
    };

    Lane();
    Lane(float coordinateYOfLane, LaneName laneName);
    Lane(LaneName laneName, std::ifstream &input);
    virtual ~Lane() = default;
    void saveCoordinates(std::ofstream &output);
    virtual void save(std::ofstream &output) = 0;

    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    float getCoordinateYOfLane() const;

    LaneName getLaneName();

    void move(float deltaY);

private:
    float coordinateYOfLane;
    LaneName laneName;
};

#endif
