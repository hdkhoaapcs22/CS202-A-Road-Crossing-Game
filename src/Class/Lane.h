#ifndef LANE_H
#define LANE_H

#include <iostream>

class Lane {
public:
    enum class LaneName {
        RoadLane,
        SafeLane,
        RiverLane
    };

private:
    int coordinateYOfLane;
    std::string saveID;
    LaneName laneName;
};

#endif
