#ifndef UNSTOPPABLE1_H
#define UNSTOPPABLE1_H

#include "../Class/Enemy.h"

class Unstoppable1 : public Enemy {
public:
    Unstoppable1(Direction direct, int coordinateXOfEnemy);

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable1;
    }

    int getSpeed() const {
        return 10;
    }

    int getWidth() const {
        return 100;
    }
};
#endif