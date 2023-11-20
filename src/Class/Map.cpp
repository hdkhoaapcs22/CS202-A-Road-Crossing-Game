#include "Map.h"
#include "RoadLane.h"
#include "SafeLane.h"

// #include "RiverLane.h"

Map::Map() {
    int numberOfSameLane = rand() % 2 + 3;
    for (int i = 0; i < numberOfSameLane; ++i) {
        if (lanes.size() == 0)
            lanes.push_back(new SafeLane(0));
        else
            lanes.push_back(new SafeLane(lanes.back()->getCoordinateYOfLane() + Lane::SIZE_OF_A_LANE));
    }
    numberOfSameLane = rand() % 4 + 1;
    insertRoadLane(numberOfSameLane);
    while (lanes.size() <= Lane::NUMBER_OF_LANES) {
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
    }
}

void Map::update(float dt, float speedMultiplier, Lane *characterLanePtr) {
    moveLanes(dt, speedMultiplier, characterLanePtr);
    for (Lane* lane : lanes) lane->update(dt);
    if (lanes.front()->getCoordinateYOfLane() <= -Lane::SIZE_OF_A_LANE) {
        delete lanes.front();
        lanes.pop_front();
        if (lanes.size() == Lane::NUMBER_OF_LANES) {
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
        return (i >= Lane::NUMBER_OF_LANES - 1) ? nullptr : *(++it);

    return nullptr;
}

void Map::insertRoadLane(int numberOfSameLane) {
    for (int i = 0; i < numberOfSameLane; ++i) {
        Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
        lanes.push_back(new RoadLane(enemyID, lanes.back()->getCoordinateYOfLane() + Lane::SIZE_OF_A_LANE));
    }
}

void Map::insertSafeLane(int numberOfSameLane) {
    for (int i = 0; i < numberOfSameLane; ++i)
        lanes.push_back(new SafeLane(lanes.back()->getCoordinateYOfLane() + Lane::SIZE_OF_A_LANE));
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
