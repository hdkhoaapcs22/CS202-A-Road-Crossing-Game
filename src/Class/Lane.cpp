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

void Lane::move(float dt, float speedMultipler, int indexLaneOfCharacter) {
    int mapSpeed = BASE_SPEED + std::max(0, indexLaneOfCharacter - NUMBER_OF_LANES / 2) * SIZE_OF_A_LANE * 10;
    coordinateYOfLane += mapSpeed * speedMultipler * dt;
}
