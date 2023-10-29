#ifndef LANE_H
#define LANE_H

#include <iostream>

class Lane {
public:
    static const int CELL_IN_LANE = 13;
    enum class LaneName {
        RoadLane,
        SafeLane,
        RiverLane
    };
    
    virtual void update(float dt) = 0;
private:
    int coordinateYOfLane;
    std::string saveID;
    LaneName laneName;
};

#endif
