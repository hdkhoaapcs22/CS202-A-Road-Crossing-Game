#include "Map.h"
#include "RoadLane.h"
#include "SafeLane.h"
#include "FireLane.h"

Map::Map() {
    initializeGUI();

    int numberOfSameLane = rand() % 2 + 3;
    lanes.push_back(new SafeLane(Config::WINDOW_HEIGHT, false));
    for (int i = 0; i < numberOfSameLane - 1; ++i)
        lanes.push_back(
            new SafeLane(lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE, false));
    numberOfSameLane = rand() % 4 + 1;
    insertRoadLane(numberOfSameLane);
    generateLanes();
}

Map::Map(std::ifstream& input) {
    initializeGUI();
    int size;
    input >> size;
    lanes.resize(size);
    for (Lane*& lane : lanes) {
        int biomeInt;
        input >> biomeInt;
        Lane::Biome laneBiome = static_cast<Lane::Biome>(biomeInt);
        int laneInt;
        input >> laneInt;
        Lane::LaneName laneName = static_cast<Lane::LaneName>(laneInt);
        switch (laneName) {
            case Lane::LaneName::RoadLane:
                lane = new RoadLane(input, laneBiome);
                break;
            case Lane::LaneName::SafeLane:
                lane = new SafeLane(input, laneBiome);
                break;
            case Lane::LaneName::FireLane:
                lane = new FireLane(input, laneBiome);
                break;
            default:
                break;
        }
    }
    input >> moving;
    int biomeInt;
    input >> biomeInt;
    biome = static_cast<Lane::Biome>(biomeInt);
}

void Map::save(std::ofstream& output) {
    output << lanes.size() << std::endl;
    for (Lane* lane : lanes) {
        output << static_cast<int>(lane->getBiome()) << std::endl;
        output << static_cast<int>(lane->getLaneName()) << std::endl;
        lane->save(output);
    }
    output << moving << std::endl;
    output << static_cast<int>(biome) << std::endl;
}

void Map::update(float dt, float speedMultiplier, Lane* characterLanePtr) {
    if (moving)
        moveLanes(dt, speedMultiplier, characterLanePtr);
    while (lanes.front()->getCoordinateYOfLane()
           >= Config::WINDOW_HEIGHT + Config::SIZE_OF_A_LANE) {
        delete lanes.front();
        lanes.pop_front();
        generateLanes(speedMultiplier);
    }
    for (Lane* lane : lanes) lane->update(dt);
}

void Map::drawUpper(Lane* characterLanePtr) {
    for (auto it = lanes.rbegin(); it != lanes.rend(); ++it) {
        (*it)->draw();
        if (*it == characterLanePtr)
            break;
    }
}

void Map::drawLower(Lane* characterLanePtr) {
    auto it = lanes.rbegin();
    for (; it != lanes.rend(); ++it) {
        if (*it == characterLanePtr)
            break;
    }
    if (it != lanes.rend())
        ++it;
    for (; it != lanes.rend(); ++it) {
        (*it)->draw();
    }
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
        int changeBiome = rand() % 10;
        if (changeBiome == 0) {
            biome = static_cast<Lane::Biome>(rand() % 5);
        }
        Enemy::EnemyID enemyID = static_cast<Enemy::EnemyID>(rand() % 10);
        lanes.push_back(
            new RoadLane(enemyID, lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE, biome));
    }
}

void Map::insertSafeLane(int numberOfSameLane) {
    for (int i = 0; i < numberOfSameLane; ++i)
        lanes.push_back(
            new SafeLane(lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE));
}

void Map::insertFireLane(int numberOfSameLane) {
    for (int i = 0; i < numberOfSameLane; ++i) {
        int changeBiome = rand() % 10;
        if (changeBiome == 0) {
            biome = static_cast<Lane::Biome>(rand() % 5);
        }
        lanes.push_back(
            new FireLane(lanes.back()->getCoordinateYOfLane() - Config::SIZE_OF_A_LANE, biome));
    }
}

void Map::initializeGUI() {
}

void Map::generateLanes(float speedMultiplier) {
    while (lanes.size() <= Config::NUMBER_OF_LANES) {
        int difficulty = (speedMultiplier - 1) * 2 + 1;
        int numberOfSameLane = rand() % difficulty + 1;
        Lane::LaneName laneName = static_cast<Lane::LaneName>(rand() % 3);
        switch (laneName) {
            case Lane::LaneName::RoadLane:
                insertRoadLane(numberOfSameLane);
                break;
            case Lane::LaneName::SafeLane:
                insertSafeLane(numberOfSameLane);
                break;
            case Lane::LaneName::FireLane:
                insertFireLane(numberOfSameLane / 2);
                break;
        }
    }
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

Lane* Map::getLaneK(int k) {
    return lanes[k];
}

int Map::getLaneID(Lane* lanePtr) {
    int index = 0;
    for (std::deque<Lane*>::iterator it = lanes.begin(); it != lanes.end(); ++it, ++index)
        if (*it == lanePtr)
            return index;
    return -1;
}

void Map::setMoving(bool moving) {
    this->moving = moving;
}
