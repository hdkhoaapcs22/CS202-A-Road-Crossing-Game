#ifndef STOPPABLE3_H
#define STOPPABLE3_H

#include "../Class/Enemy.h"

class Stoppable3 : public Enemy {
public:
    Stoppable3(Direction direct, int coordinateXOfEnemy);
    Stoppable3(std::ifstream& input);

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable3;
    }

    int getSpeed() const {
        return 200;
    }

    int getWidth() const {
        return 100;
    }

private:
    void initializeGUI();
};
#endif