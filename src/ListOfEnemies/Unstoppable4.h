#ifndef UNSTOPPABLE4_H
#define UNSTOPPABLE4_H

#include "../Class/Enemy.h"

class Unstoppable4 : public Enemy {
public:
    Unstoppable4(Direction direct, int coordinateXOfEnemy);
    Unstoppable4(std::ifstream& input);

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable4;
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