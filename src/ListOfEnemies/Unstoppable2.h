#ifndef UNSTOPPABLE2_H
#define UNSTOPPABLE2_H

#include "../Class/Enemy.h"
class Unstoppable2 : public Enemy{
public:
    Unstoppable2(Direction direct, int coordinateXOfEnemy);
    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable2;
    }
    int getSpeed() const {
        return 0;
    }
    int getWidth() const {
        return 0;
    }
};
#endif