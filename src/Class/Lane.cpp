#include "Lane.h"

Lane::Lane()
: coordinateYOfLane(0)
, saveID("")
, laneName() {
}

Lane::Lane(std::ifstream& input) {
    input >> coordinateYOfLane;
    int laneNameId;
    input >> laneNameId;
    laneName = static_cast<Lane::LaneName>(laneNameId);
};

Lane::Lane(float coordinateYOfLane)
: coordinateYOfLane(coordinateYOfLane)
, saveID("")
, laneName(){};

Lane::Lane(float coordinateYOfLane, LaneName laneName)
: coordinateYOfLane(coordinateYOfLane)
, saveID("")
, laneName(laneName){};

float Lane::getCoordinateYOfLane() const {
    return coordinateYOfLane;
}

Lane::LaneName Lane::getLaneName() {
    return laneName;
}

void Lane::move(float deltaY) {
    coordinateYOfLane += deltaY;
}

void Lane::save(std::ofstream& output) {
    output << coordinateYOfLane << static_cast<int>(laneName);
}
