#include "Lane.h"

Lane::Lane()
: coordinateYOfLane(0)
, saveID("")
, laneName(){};

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
