#ifndef STOPPABLE1_H
#define STOPPABLE1_H

#include "../Class/Enemy.h"

class Stoppable1 : public Enemy {
public:
    Stoppable1(Direction direct, int coordinateXOfEnemy);

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable1;
    }

    int getSpeed() const {
        return 0;
    }

    int getWidth() const {
        return 0;
    }
};
#endif