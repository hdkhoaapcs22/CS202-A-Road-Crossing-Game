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

    Lane();
    Lane(int coordinateYOfLane);
    Lane(int coordinateYOfLane, LaneName laneName);

    static const int CELL_IN_LANE = 13;

    virtual void update(float dt) = 0;

private:
    int coordinateYOfLane;
    std::string saveID;
    LaneName laneName;
};

#endif
