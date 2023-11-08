#include "RoadLane.h"

RoadLane::RoadLane()
: Lane()
, hasTrafficLight(false)
, isRedSignal(false)
, breakTimer(0)
, enemyID(0) {
}

void RoadLane::manageTraffic(float dt) {
    checkHasTrafficLight();
    int direction = randomDirection();

    if (hasTrafficLight) {
        if (!isRedSignal) {
            for (Enemy *enemy : enemies) {
                enemy->moveEnemy(direction, dt);
            }
        }
    } else {
        for (Enemy *enemy : enemies) {
            enemy->moveEnemy(direction, dt);
        }
    }
}

void RoadLane::checkHasTrafficLight() {
    switch (enemyID) {
        case 0:
        case 1:
        case 2:
        case 3: {
            hasTrafficLight = true;
            break;
        }
        default:
            break;
    }
}

int RoadLane::randomDirection() {
    return rand() % 2;
}

void RoadLane::update(float dt) {
    manageTraffic(dt);
    breakTimer += dt;
    if (breakTimer >= BREAK_TIME) {
        breakTimer = 0;
        isRedSignal = !isRedSignal;
    }
}
