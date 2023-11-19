#include "Enemy.h"

void Enemy::moveEnemy(float dt) {
    coordinateX += static_cast<int>(direct) * (this->getSpeed()) * dt;
}

int Enemy::getCoordinateXOfEnemy() {
    return coordinateX;
}

Enemy::Enemy(Direction direct, int coordinateXOfEnemy)
: direct(direct)
, coordinateX(coordinateXOfEnemy) {
}