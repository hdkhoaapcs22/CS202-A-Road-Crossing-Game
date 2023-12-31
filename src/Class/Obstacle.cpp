#include "Obstacle.h"
#include "Lane.h"

Obstacle::Obstacle()
: coordinateXOfObstacles(randomCoordinateXOfObstacles())
, obstacleName(randomObstacleName()) {
}

Obstacle::Obstacle(std::ifstream& input) {
    input >> coordinateXOfObstacles;
    int obstacleNameInt;
    input >> obstacleNameInt;
    obstacleName = static_cast<ObstacleName>(obstacleNameInt);
}

void Obstacle::save(std::ofstream& output) {
    output << coordinateXOfObstacles << " " << static_cast<int>(obstacleName);
}

Obstacle::ObstacleName Obstacle::randomObstacleName() {
    int randomName = rand() % 2;
    if (randomName == 0) {
        return ObstacleName::Rock;
    }
    return ObstacleName::Tree;
}

int Obstacle::randomCoordinateXOfObstacles() {
    int randomCoordinateXOfObstacles = rand() % Config::CELL_IN_LANE;
    return randomCoordinateXOfObstacles;
}

int Obstacle::getCoordinateX() const {
    return coordinateXOfObstacles;
}

void Obstacle::setCoordinateX(int x) {
    coordinateXOfObstacles = x;
}

void Obstacle::draw(int coordinateYOfLane) {
    DrawRectangle(coordinateXOfObstacles * Config::WIDTH_OF_EACH_CELL, coordinateYOfLane,
                  Config::WIDTH_OF_EACH_CELL, Config::WIDTH_OF_EACH_CELL, BLUE);
}

void Obstacle::initializeGUI() {
}
