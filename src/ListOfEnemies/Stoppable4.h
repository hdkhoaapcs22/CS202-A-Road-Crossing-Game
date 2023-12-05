#ifndef STOPPABLE4_H
#define STOPPABLE4_H

#include "../Class/Enemy.h"

class Stoppable4 : public Enemy {
public:
    Stoppable4(Direction direct, int coordinateXOfEnemy);

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable4;
    }

    int getSpeed() const {
        return 200;
    }

    int getWidth() const {
        return 100;
    }
};
#endif