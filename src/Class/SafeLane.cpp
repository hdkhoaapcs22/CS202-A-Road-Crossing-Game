#include "SafeLane.h"

SafeLane::SafeLane(float coordinateYOfLane, bool hasObstacle)
: Lane(coordinateYOfLane, Lane::LaneName::SafeLane) {
    initializeGUI();

    if (hasObstacle) {
        int obstaclesNum = rand() % 5;
        for (int i = 0; i < obstaclesNum; ++i) {
            Obstacle* newObstacle = new Obstacle();
            while (checkOverlap(newObstacle->getCoordinateX())) {
                newObstacle->setCoordinateX(newObstacle->randomCoordinateXOfObstacles());
            }
            obstacles.push_back(newObstacle);
        }
    }
}

SafeLane::SafeLane(std::ifstream& input)
: Lane(Lane::LaneName::SafeLane, input) {
    initializeGUI();
    int numOfObstacles;
    input >> numOfObstacles;
    obstacles.resize(numOfObstacles);
    for (Obstacle*& obstacle : obstacles) obstacle = new Obstacle(input);
}

void SafeLane::save(std::ofstream& output) {
    Lane::saveCoordinates(output);
    output << obstacles.size() << std::endl;
    for (int i = 0; i < obstacles.size(); ++i) {
        obstacles[i]->save(output);
    }
    output << std::endl;
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
    float coordinateYOfLane = getCoordinateYOfLane() - Config::SIZE_OF_A_LANE / 2;
    mTexture->setPosition({0, coordinateYOfLane});
    mTexture->draw();
    for (Obstacle* ptr : obstacles) {
        ptr->draw(coordinateYOfLane);
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

void SafeLane::initializeGUI() {
    mTexture = std::make_shared<GUITexture>();
    mTexture->setTexture(TextureHolder::get(TextureID::SafeLane));
    mTexture->setSize({Config::WINDOW_WIDTH, Config::SIZE_OF_A_LANE});
}
