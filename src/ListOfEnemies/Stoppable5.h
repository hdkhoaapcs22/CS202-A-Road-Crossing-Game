#ifndef STOPPABLE5_H
#define STOPPABLE5_H

#include "../Class/Enemy.h"

class Stoppable5 : public Enemy {
public:
    Stoppable5(Direction direct, int coordinateXOfEnemy);
    Stoppable5(std::ifstream& input);

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable5;
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