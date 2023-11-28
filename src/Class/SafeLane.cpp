#include "SafeLane.h"

SafeLane::SafeLane(float coordinateYOfLane)
: Lane(coordinateYOfLane, Lane::LaneName::SafeLane) {
    mTexture = std::make_shared<GUITexture>();
    mTexture->setTexture(TextureHolder::get(TextureID::SafeLane));
    mTexture->setSize({Config::WINDOW_WIDTH, Config::SIZE_OF_A_LANE});

    int obstaclesNum = rand() % 5;
    for (int i = 0; i < obstaclesNum; ++i) {
        Obstacle* newObstacle = new Obstacle();
        while (checkOverlap(newObstacle->getCoordinateX())) {
            newObstacle->setCoordinateX(newObstacle->randomCoordinateXOfObstacles());
        }
        obstacles.push_back(newObstacle);
    }
}

SafeLane::~SafeLane() {
    for (Obstacle*& ptr : obstacles) {
        delete ptr;
        ptr = nullptr;
    }
}

void SafeLane::update(float dt) {
}

void SafeLane::draw() {
    mTexture->setPosition({0, getCoordinateYOfLane()});
    mTexture->draw();
    for (Obstacle* ptr : obstacles) {
        ptr->draw(getCoordinateYOfLane());
    }
}

bool SafeLane::checkOverlap(int x) {
    for (Obstacle* ptr : obstacles) {
        if (x == ptr->getCoordinateX()) {
            return true;
        }
    }
    return false;
}
