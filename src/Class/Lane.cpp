#include "Lane.h"

Lane::Lane()
: coordinateYOfLane(0)
, laneName(){};

Lane::Lane(float coordinateYOfLane, LaneName laneName)
: coordinateYOfLane(coordinateYOfLane)
, laneName(laneName) {
}

Lane::Lane(LaneName laneName, std::ifstream& input)
: laneName(laneName) {
    input >> coordinateYOfLane;
}

void Lane::saveCoordinates(std::ofstream& output) {
    output << coordinateYOfLane << std::endl;
}

float Lane::getCoordinateYOfLane() const {
    return coordinateYOfLane;
}

Lane::LaneName Lane::getLaneName() {
    return laneName;
}

void Lane::move(float deltaY) {
    coordinateYOfLane += deltaY;
}
