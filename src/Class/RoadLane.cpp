#include "RoadLane.h"

RoadLane::RoadLane(Enemy::EnemyID enemyID, float coordinateYOfLane)
: Lane(coordinateYOfLane, Lane::LaneName::RoadLane)
, hasTrafficLight(false)
, isRedSignal(false)
, breakTimer(0)
, spawnTimer(0)
, enemyID(enemyID) {
    int x = rand() % 2;
    if (x == 0) {
        direct = Direction::Left;
    } else {
        direct = Direction::Right;
    }
    // Create temporary enemy
    createEnemy(enemyID, 0);
    int enemySpeed = enemies.back()->getSpeed();
    int enemyWidth = enemies.back()->getWidth();
    deleteEnemiesBack();

    spawnTime = (float)(enemyWidth + Config::ENEMY_DISTANCE) / enemySpeed;
    checkHasTrafficLight();

    update(100 + rand() % 100); // advance forward to populate the lane
}

void RoadLane::manageTraffic(float dt) {
    int tmp = enemies.size();
    for (int i = 0; i < tmp; ++i) {
        enemies[i]->moveEnemy(dt);
    }

    if (!enemies.empty())
        manageEnemies(enemies[0]);
    spawnTimer += dt;
    if (spawnTimer >= spawnTime) {
        while (spawnTimer >= spawnTime) {
            spawnTimer -= spawnTime;
            // Create a temporary enemy to get the speed in case of the queue is empty
            createEnemy(enemyID, 0);
            int enemySpeed = enemies.back()->getSpeed();
            deleteEnemiesBack();

            if (!hasTrafficLight || !isRedSignal) // Only spawn when the signal is green
                if (direct == Direction::Right) {
                    createEnemy(enemyID, 0 + spawnTimer * enemySpeed);
                } else {
                    createEnemy(enemyID, Config::WINDOW_WIDTH - spawnTimer * enemySpeed);
                }
        }
    }
}

void RoadLane::manageEnemies(Enemy *enemy) {
    if (enemy->getCoordinateXOfEnemy() > Config::WINDOW_WIDTH
        || enemy->getCoordinateXOfEnemy() < 0) {
        delete enemies.front();
        enemies.pop_front();
    }
}

void RoadLane::checkHasTrafficLight() {
    switch (enemyID) {
        case Enemy::EnemyID::Stoppable1:
        case Enemy::EnemyID::Stoppable2:
        case Enemy::EnemyID::Stoppable3:
        case Enemy::EnemyID::Stoppable4:
        case Enemy::EnemyID::Stoppable5:
            hasTrafficLight = true;
            break;
        default:
            break;
    }
}

void RoadLane::update(float dt) {
    manageTraffic(dt);
    breakTimer += dt;
    while (breakTimer >= BREAK_TIME) {
        breakTimer -= BREAK_TIME;
        isRedSignal = !isRedSignal;
    }
}

void RoadLane::draw() {
    float coordinateYOfLane = getCoordinateYOfLane() - Config::SIZE_OF_A_LANE / 2;
    DrawRectangle(0, coordinateYOfLane, Config::WINDOW_WIDTH, Config::SIZE_OF_A_LANE, GRAY);

    for (Enemy *enemy : enemies) {
        enemy->draw(coordinateYOfLane);
    }

    if (hasTrafficLight) {
        if (direct == Direction::Right) {
            if (isRedSignal)
                DrawRectangle(0, coordinateYOfLane, 50, Config::SIZE_OF_A_LANE, BLACK);
        } else {
            if (isRedSignal)
                DrawRectangle(Config::WINDOW_WIDTH - 50, coordinateYOfLane, 50,
                              Config::SIZE_OF_A_LANE, BLACK);
        }
    }
}

RoadLane::~RoadLane() {
    for (Enemy *enemy : enemies) {
        delete enemy;
    }
}

bool RoadLane::checkCollision(int leftHitbox, int rightHitbox) {
    for (Enemy *enemy : enemies)
        if (enemy->checkCollision(leftHitbox, rightHitbox))
            return true;
    return false;
}

void RoadLane::createEnemy(Enemy::EnemyID enemyID, float startingX) {
    switch (enemyID) {
        case Enemy::EnemyID::Unstoppable1:
            enemies.push_back(new Unstoppable1(direct, startingX));
            break;
        case Enemy::EnemyID::Unstoppable2:
            enemies.push_back(new Unstoppable1(direct, startingX));
            break;
        case Enemy::EnemyID::Unstoppable3:
            enemies.push_back(new Unstoppable1(direct, startingX));
            break;
        case Enemy::EnemyID::Unstoppable4:
            enemies.push_back(new Unstoppable1(direct, startingX));
            break;
        case Enemy::EnemyID::Unstoppable5:
            enemies.push_back(new Unstoppable1(direct, startingX));
            break;
        case Enemy::EnemyID::Stoppable1:
            enemies.push_back(new Stoppable1(direct, startingX));
            break;
        case Enemy::EnemyID::Stoppable2:
            enemies.push_back(new Stoppable2(direct, startingX));
            break;
        case Enemy::EnemyID::Stoppable3:
            enemies.push_back(new Stoppable3(direct, startingX));
            break;
        case Enemy::EnemyID::Stoppable4:
            enemies.push_back(new Stoppable4(direct, startingX));
            break;
        case Enemy::EnemyID::Stoppable5:
            enemies.push_back(new Stoppable5(direct, startingX));
            break;
        default:
            break;
    }
}

void RoadLane::deleteEnemiesBack() {
    delete enemies.back();
    enemies.pop_back();
}
