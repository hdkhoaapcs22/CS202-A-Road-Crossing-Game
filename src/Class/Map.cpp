#include "Map.h"
#include "RoadLane.h"
#include "SafeLane.h"

// #include "RiverLane.h"

Map::Map() {
    int numberOfSameLane = rand() % 3 + 2;
    for (int i = 0; i < numberOfSameLane; ++i) {
        if (lanes.size() == 0)
            lanes.push_back(new SafeLane(0));
        else
            lanes.push_back(new SafeLane(lanes.back()->getCoordinateYOfLane() + sizeOfALane));
    }
    numberOfSameLane = rand() % 4 + 1;
    for (int i = 0; i < numberOfSameLane; ++i) {
        Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
        lanes.push_back(new RoadLane(enemyID, lanes.back()->getCoordinateYOfLane() + sizeOfALane));
    }
    while (lanes.size() <= Lane::CELL_IN_LANE) {
        numberOfSameLane = rand() % 4 + 1;
        Lane::LaneName laneName = static_cast<Lane::LaneName>(rand() % 3);
        while (lanes.back()->getLaneName() == laneName)
            laneName = static_cast<Lane::LaneName>(rand() % 3);
        switch (laneName) {
            case Lane::LaneName::RoadLane:
                for (int i = 0; i < numberOfSameLane; ++i) {
                    Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
                    lanes.push_back(
                        new RoadLane(enemyID, lanes.back()->getCoordinateYOfLane() + sizeOfALane));
                }
                break;
            case Lane::LaneName::SafeLane:
                for (int i = 0; i < numberOfSameLane; ++i)
                    lanes.push_back(
                        new SafeLane(lanes.back()->getCoordinateYOfLane() + sizeOfALane));
                break;
            default:
                /* for (int i = 0; i < numberOfSameLane; ++i)
                    lanes.push_back(new RiverLane(lanes.back()->getCoordinateYOfLane() +
                   sizeOfALane));*/
                break;
        }
    }
}

void Map::update(float dt, double speedMultiplier) {
    for (Lane* lane : lanes) lane->update(dt);
    moveLanes(dt, speedMultiplier);
    if (lanes.front()->getCoordinateYOfLane() == -sizeOfALane) {
        delete lanes.front();
        lanes.pop_front();
        if (lanes.size() == Lane::CELL_IN_LANE) {
            int numberOfSameLane = rand() % 4 + 1;
            Lane::LaneName laneName = static_cast<Lane::LaneName>(rand() % 3);
            while (lanes.back()->getLaneName() == laneName)
                laneName = static_cast<Lane::LaneName>(rand() % 3);
            switch (laneName) {
                case Lane::LaneName::RoadLane:
                    for (int i = 0; i < numberOfSameLane; ++i) {
                        Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
                        lanes.push_back(new RoadLane(
                            enemyID, lanes.back()->getCoordinateYOfLane() + sizeOfALane));
                    }
                    break;
                case Lane::LaneName::SafeLane:
                    for (int i = 0; i < numberOfSameLane; ++i)
                        lanes.push_back(
                            new SafeLane(lanes.back()->getCoordinateYOfLane() + sizeOfALane));
                    break;
                default:
                    /* for (int i = 0; i < numberOfSameLane; ++i)
                        lanes.push_back(new RiverLane(lanes.back()->getCoordinateYOfLane() +
                        sizeOfALane));*/
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

void Map::moveLanes(float dt, double speedMultiplier) {
    for (Lane* lane : lanes) lane->move(dt, speedMultiplier, baseSpeed);
}

Lane* Map::iteratorLanes(Lane* curLanePtr, const std::string& direction) {
    if (lanes.empty())
        return nullptr;
    std::deque<Lane*>::iterator it = lanes.begin();
    for (; it != lanes.end(); ++it)
        if (*it == curLanePtr)
            break;

    if (direction == "DOWN")
        return (it == lanes.begin()) ? nullptr : *(--it);

    if (direction == "UP")
        return (it == lanes.end() - 1) ? nullptr : *(++it);

    return nullptr;
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
    for (std::deque<Lane*>::iterator it = lanes.begin(); it != lanes.end(); ++it)
        if ((*it)->getLaneName() != Lane::LaneName::SafeLane)
            return *(--it);
    return nullptr;
}
