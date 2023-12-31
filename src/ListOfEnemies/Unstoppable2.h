#ifndef UNSTOPPABLE2_H
#define UNSTOPPABLE2_H

#include "../Class/Enemy.h"

class Unstoppable2 : public Enemy {
public:
    Unstoppable2(Direction direct, int coordinateXOfEnemy);
    Unstoppable2(std::ifstream& input);

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable2;
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