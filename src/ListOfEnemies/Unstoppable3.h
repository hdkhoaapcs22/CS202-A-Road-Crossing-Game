#ifndef UNSTOPPABLE3_H
#define UNSTOPPABLE3_H

#include "../Class/Enemy.h"

class Unstoppable3 : public Enemy {
public:
    Unstoppable3(Direction direct, int coordinateXOfEnemy);

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable3;
    }

    int getSpeed() const {
        return 0;
    }

    int getWidth() const {
        return 0;
    }
};
#endif