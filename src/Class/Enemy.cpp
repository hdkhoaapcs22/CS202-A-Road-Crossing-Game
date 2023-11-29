#include "Enemy.h"

void Enemy::moveEnemy(float dt) {
    coordinateX += static_cast<int>(direct) * (this->getSpeed()) * dt;
}

float Enemy::getCoordinateXOfEnemy() {
    return coordinateX;
}

bool Enemy::checkCollision(int leftHitbox, int rightHitbox) {
    return coordinateX + this->getWidth() / 2 > leftHitbox
        && coordinateX - this->getWidth() / 2 < rightHitbox;
}

void Enemy::draw(float coordinateYOfLane) {
    float coordinateXOfEnemy = coordinateX - this->getWidth() / 2;
    float coordinateYOfEnemy = coordinateYOfLane;
    DrawRectangle(coordinateXOfEnemy, coordinateYOfEnemy, this->getWidth(), Config::SIZE_OF_A_LANE,
                  RED);
}

Enemy::Enemy(Direction direct, float coordinateXOfEnemy)
: direct(direct)
, coordinateX(coordinateXOfEnemy) {
}
