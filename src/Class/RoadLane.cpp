#include "RoadLane.h"

RoadLane::RoadLane(Enemy::EnemyID enemyID, float coordinateYOfLane)
: Lane(coordinateYOfLane, Lane::LaneName::RoadLane)
, hasTrafficLight(false)
, isRedSignal(false)
, breakTimer(0)
, enemyID(enemyID) {
    int x = rand() % 2;
    if (x == 0) {
        direct = Direction::Left;
        float startingX = 0 + rand() % (Config::ENEMY_DISTANCE);
        while (startingX < Config::WINDOW_WIDTH) {
            createEnemy(enemyID, startingX);
            startingX += enemies.back()->getWidth() + Config::ENEMY_DISTANCE;
        }
    } else {
        direct = Direction::Right;
        float startingX = Config::WINDOW_WIDTH - rand() % (Config::ENEMY_DISTANCE);
        while (startingX > 0) {
            createEnemy(enemyID, startingX);
            startingX -= enemies.back()->getWidth() + Config::ENEMY_DISTANCE;
        }
    }

    checkHasTrafficLight();
}

void RoadLane::manageTraffic(float dt) {
    if (!hasTrafficLight || !isRedSignal) {
        int tmp = enemies.size();
        for (int i = 0; i < tmp; ++i) {
            enemies[i]->moveEnemy(dt);
        }
    }
    manageEnemies(enemies[0]);
    if (direct == Direction::Right) {
        if (enemies.back()->getCoordinateXOfEnemy()
            > enemies.back()->getWidth() + Config::ENEMY_DISTANCE) {
            createEnemy(enemyID, 0);
        }
    } else {
        if (enemies.back()->getCoordinateXOfEnemy()
            < Config::WINDOW_WIDTH - enemies.back()->getWidth() - Config::ENEMY_DISTANCE) {
            createEnemy(enemyID, Config::WINDOW_WIDTH);
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
    if (breakTimer >= BREAK_TIME) {
        breakTimer = 0;
        isRedSignal = !isRedSignal;
    }
}

void RoadLane::draw() {
    float coordinateYOfLane = getCoordinateYOfLane() - Config::SIZE_OF_A_LANE / 2;
    DrawRectangle(0, coordinateYOfLane, Config::WINDOW_WIDTH, Config::SIZE_OF_A_LANE, GRAY);

    for (Enemy *enemy : enemies) {
        enemy->draw(coordinateYOfLane);
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
