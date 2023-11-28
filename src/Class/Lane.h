#ifndef LANE_H
#define LANE_H

#include <iostream>
#include "../Config.h"

class Lane {
public:
    enum class LaneName {
        RoadLane,
        SafeLane,
        RiverLane
    };

    Lane();
    Lane(float coordinateYOfLane);
    Lane(float coordinateYOfLane, LaneName laneName);


    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    float getCoordinateYOfLane() const;

    LaneName getLaneName();

    void move(float dt, float speedMultipler, int indexLaneOfCharacter);

private:
    float coordinateYOfLane;
    std::string saveID;
    LaneName laneName;
};

#endif
