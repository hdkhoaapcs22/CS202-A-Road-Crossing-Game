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
        return 100;
    }

    int getWidth() const {
        return 100;
    }

private:
    void initializeGUI();
};
#endif