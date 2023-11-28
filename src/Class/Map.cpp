#include "Map.h"
#include "RoadLane.h"
#include "SafeLane.h"

// #include "RiverLane.h"

Map::Map() {
    std::cout << "Map constructor" << std::endl;
    int numberOfSameLane = rand() % 2 + 3;
    lanes.push_back(new SafeLane(Config::WINDOW_HEIGHT));
    insertSafeLane(numberOfSameLane - 1);
    numberOfSameLane = rand() % 4 + 1;
    insertRoadLane(numberOfSameLane);
    std::cout << "Map constructor" << std::endl;
    while (lanes.size() <= Config::NUMBER_OF_LANES) {
        std::cout << lanes.size() << std::endl;
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
                //insertRiverLane(numberOfSameLane);
                break;
        }
        std::cout << lanes.size() << std::endl;
    }
    std::cout << "Map constructor" << std::endl;
}

void Map::update(float dt, float speedMultiplier, Lane *characterLanePtr) {
    moveLanes(dt, speedMultiplier, characterLanePtr);
    for (Lane* lane : lanes) lane->update(dt);
    if (lanes.front()->getCoordinateYOfLane() >= Config::WINDOW_HEIGHT + Config::SIZE_OF_A_LANE) {
        delete lanes.front();
        lanes.pop_front();
        if (lanes.size() == Config::NUMBER_OF_LANES) {
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
                    //insertRiverLane(numberOfSameLane);
                    break;
            }
        }
    }
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

void Map::moveLanes(float dt, float speedMultiplier, Lane *characterLanePtr) {
    int index = 0;
    for (std::deque<Lane*>::iterator it = lanes.begin(); it != lanes.end(); ++it, ++index)
        if (*it == characterLanePtr) break;
    for (Lane* lane : lanes) lane->move(dt, speedMultiplier, index);
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
    std::cout << "insertRoadLane " << numberOfSameLane << std::endl;
    for (int i = 0; i < numberOfSameLane; ++i) {
        std::cout << "insertRoadLane" << std::endl;
        Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
        lanes.push_back(
            new RoadLane(enemyID, lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE));
    }
}

void Map::insertSafeLane(int numberOfSameLane) {
    std::cout << "insertSafeLane " << numberOfSameLane << std::endl;
    for (int i = 0; i < numberOfSameLane; ++i)
        std::cout << "insertSafeLane" << std::endl;
        lanes.push_back(
            new SafeLane(lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE));
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
