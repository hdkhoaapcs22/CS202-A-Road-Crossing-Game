#ifndef UNSTOPPABLE1_H
#define UNSTOPPABLE1_H

#include "../Class/Enemy.h"

class Unstoppable1 : public Enemy {
public:
    Unstoppable1(Direction direct, int coordinateXOfEnemy);
    Unstoppable1(std::ifstream& input);

    TextureID getTextureID() const {
        return TextureID::Unstoppable1;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable1;
    }

    int getSpeed() const {
        return 150;
    }

    int getWidth() const {
        return 93;
    }
};
#endif