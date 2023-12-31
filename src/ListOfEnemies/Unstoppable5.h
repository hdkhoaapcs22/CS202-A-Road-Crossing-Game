#ifndef UNSTOPPABLE5_H
#define UNSTOPPABLE5_H

#include "../Class/Enemy.h"

class Unstoppable5 : public Enemy {
public:
    Unstoppable5(Direction direct, int coordinateXOfEnemy);
    Unstoppable5(std::ifstream& input);

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable5;
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