#include "Map.h"

Lane* Map::iteratorLanes(Lane* curLanePtr, const std::string& direction) {
    if (lanes.empty()) {
        return nullptr;
    }
    std::deque<Lane*>::iterator it = lanes.begin();
    for (; it != lanes.end(); ++it) {
        if (*it == curLanePtr) {
            break;
        }
    }

    if (direction == "DOWN") {
        return *(--it);
    }

    if (direction == "UP")
        return *(++it);

    return nullptr;
}

Lane* Map::getNextLane(Lane* curLanePtr) {
    return iteratorLanes(curLanePtr, "UP");
}

Lane* Map::getPreviousLane(Lane* curLanePtr) {
    return iteratorLanes(curLanePtr, "DOWN");
}
