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
        return ObstacleName::Type1;
    }
    return ObstacleName::Type2;
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
    if (obstacleName == ObstacleName::Type1) {
        mTexture->setPosition({(float)coordinateXOfObstacles * Config::WIDTH_OF_EACH_CELL,
                               (float)coordinateYOfLane - 26});
    } else {
        mTexture->setPosition({(float)coordinateXOfObstacles * Config::WIDTH_OF_EACH_CELL,
                               (float)coordinateYOfLane - 50});
    }
    mTexture->draw();
}

void Obstacle::initializeGUI() {
    mTexture = std::make_shared<GUITexture>();
    if (obstacleName == ObstacleName::Type1) {
        mTexture->setTexture(TextureHolder::get(TextureID::ObstacleType1));
    } else {
        mTexture->setTexture(TextureHolder::get(TextureID::ObstacleType2));
    }
    mTexture->setSize({0, 0}); // Use default size
}
