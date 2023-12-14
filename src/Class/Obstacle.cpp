#include "Obstacle.h"
#include "Lane.h"

Obstacle::Obstacle()
: coordinateXOfObstacles(randomCoordinateXOfObstacles())
, obstacleName(randomObstacleName()) {
    initializeGUI();
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
    mTexture->setPosition({(float)coordinateXOfObstacles * Config::WIDTH_OF_EACH_CELL,
                           (float)coordinateYOfLane - 24});
    mTexture->draw();
}

void Obstacle::initializeGUI() {
    mTexture = std::make_shared<GUITexture>();
    mTexture->setTexture(TextureHolder::get(TextureID::Obstacle));
    mTexture->setSize({0, 0}); // Use default size
}
