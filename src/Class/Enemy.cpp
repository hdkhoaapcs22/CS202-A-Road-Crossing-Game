#include "Enemy.h"

void Enemy::moveEnemy(float dt) {
    coordinateX += static_cast<int>(direct) * (this->getSpeed()) * dt;
}

Enemy::Enemy(Direction direct, int coordinateXOfEnemy)
: direct(direct)
, coordinateX(coordinateXOfEnemy) {
}