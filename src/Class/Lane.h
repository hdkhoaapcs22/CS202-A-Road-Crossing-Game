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

    static const int CELL_IN_LANE = 13;
    static const int NUMBER_OF_LANES = 10;
    static const int SIZE_OF_A_LANE = Config::WINDOW_HEIGHT / NUMBER_OF_LANES;
    static const int BASE_SPEED = 25;

    virtual void update(float dt) = 0;

    float getCoordinateYOfLane() const;

    LaneName getLaneName();

    void move(float dt, float speedMultipler, int indexLaneOfCharacter);

private:
    float coordinateYOfLane;
    std::string saveID;
    LaneName laneName;
};

#endif
