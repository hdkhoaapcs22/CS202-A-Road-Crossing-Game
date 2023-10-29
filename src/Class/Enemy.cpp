#include "Enemy.h"

void Enemy::moveEnemy(int direction, float dt) {
    coordinateXOfEnemy += static_cast<int>(direct)*speed*dt;
}

Enemy::Enemy(EnemyID id, Direction direct, int coordinateXOfEnemy, const int spped, const int width) {
    this->id = randomEnemyID();
    this->direct = direct;
    this->coordinateXOfEnemy = coordinateXOfEnemy;
    this->speed = static_cast<int>(id)/100;
    this->width = static_cast<int>(id)%100;
}

Enemy::EnemyID Enemy::randomEnemyID() {
    int randomEnemyID = rand() % 10;
    switch (randomEnemyID)
    {
    case 0:
        return EnemyID::Stoppable1;
        break;
    case 1:
        return EnemyID::Stoppable2;
        break;
    case 2:
        return EnemyID::Stoppable3;
        break;
    case 3:
        return EnemyID::Stoppable4;
        break;
    case 4:
        return EnemyID::Stoppable5;
        break;
    case 5:
        return EnemyID::Unstoppable1;
        break;
    case 6:
        return EnemyID::Unstoppable2;
        break;
    case 7:
        return EnemyID::Unstoppable3;
        break;
    case 8:
        return EnemyID::Unstoppable4;
        break;
    case 9:
        return EnemyID::Unstoppable5;
        break;
    }
}
