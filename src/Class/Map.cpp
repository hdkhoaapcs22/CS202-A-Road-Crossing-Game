#include "Map.h"
#include "RoadLane.h"
#include "SafeLane.h"

// #include "RiverLane.h"

Map::Map() {
    initializeGUI();

    int numberOfSameLane = rand() % 2 + 3;
    lanes.push_back(new SafeLane(Config::WINDOW_HEIGHT, false));
    for (int i = 0; i < numberOfSameLane - 1; ++i)
        lanes.push_back(
            new SafeLane(lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE, false));
    numberOfSameLane = rand() % 4 + 1;
    insertRoadLane(numberOfSameLane);
    while (lanes.size() <= Config::NUMBER_OF_LANES) {
        numberOfSameLane = rand() % 4 + 1;
        Lane::LaneName laneName = static_cast<Lane::LaneName>(rand() % 3);
        switch (laneName) {
            case Lane::LaneName::RoadLane:
                insertRoadLane(numberOfSameLane);
                break;
            case Lane::LaneName::SafeLane:
                insertSafeLane(numberOfSameLane);
                break;
            default:
                // insertRiverLane(numberOfSameLane);
                break;
        }
    }
}

void Map::update(float dt, float speedMultiplier, Lane* characterLanePtr) {
    if (moving)
        moveLanes(dt, speedMultiplier, characterLanePtr);
    while (lanes.front()->getCoordinateYOfLane()
           >= Config::WINDOW_HEIGHT + Config::SIZE_OF_A_LANE) {
        delete lanes.front();
        lanes.pop_front();
        while (lanes.size() <= Config::NUMBER_OF_LANES) {
            int numberOfSameLane = rand() % 4 + 1;
            Lane::LaneName laneName = static_cast<Lane::LaneName>(rand() % 3);
            switch (laneName) {
                case Lane::LaneName::RoadLane:
                    insertRoadLane(numberOfSameLane);
                    break;
                case Lane::LaneName::SafeLane:
                    insertSafeLane(numberOfSameLane);
                    break;
                default:
                    // insertRiverLane(numberOfSameLane);
                    break;
            }
        }
    }
    for (Lane* lane : lanes) lane->update(dt);
}

void Map::draw() {
    ClearBackground(BLACK);
    for (Lane* lane : lanes) lane->draw();
}

Map::~Map() {
    for (Lane*& lane : lanes) {
        delete lane;
        lane = nullptr;
    }
}

void Map::moveLanes(float dt, float speedMultiplier, Lane* characterLanePtr) {
    int index = 0;
    for (std::deque<Lane*>::iterator it = lanes.begin(); it != lanes.end(); ++it, ++index)
        if (*it == characterLanePtr)
            break;

    float speed = Config::BASE_SPEED
                + std::max(0.0f, Config::CAMERA_OFFSET - characterLanePtr->getCoordinateYOfLane())
                      * Config::ACCERELATED_SPEED;

    for (Lane* lane : lanes) lane->move(speed * dt * speedMultiplier);
}

Lane* Map::iteratorLanes(Lane* curLanePtr, const std::string& direction) {
    if (lanes.empty())
        return nullptr;
    std::deque<Lane*>::iterator it = lanes.begin();
    int i = 0;
    for (; it != lanes.end(); ++it, ++i) {
        if (*it == curLanePtr)
            break;
    }

    if (direction == "DOWN")
        return (it == lanes.begin()) ? nullptr : *(--it);

    if (direction == "UP")
        return (i >= Config::NUMBER_OF_LANES - 1) ? nullptr : *(++it);

    return nullptr;
}

void Map::insertRoadLane(int numberOfSameLane) {
    for (int i = 0; i < numberOfSameLane; ++i) {
        Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
        lanes.push_back(
            new RoadLane(enemyID, lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE));
    }
}

void Map::insertSafeLane(int numberOfSameLane) {
    for (int i = 0; i < numberOfSameLane; ++i)
        lanes.push_back(
            new SafeLane(lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE));
}

void Map::initializeGUI() {
}

Lane* Map::getNextLane(Lane* curLanePtr) {
    return iteratorLanes(curLanePtr, "UP");
}

Lane* Map::getPreviousLane(Lane* curLanePtr) {
    return iteratorLanes(curLanePtr, "DOWN");
}

Lane* Map::getFirstLane() {
    return lanes.front();
}

Lane* Map::getFirstLaneOfCharacter() {
    return lanes[2];
}

void Map::setMoving(bool moving) {
    this->moving = moving;
}
