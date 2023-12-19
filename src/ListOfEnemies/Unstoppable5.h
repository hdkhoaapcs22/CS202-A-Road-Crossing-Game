#ifndef UNSTOPPABLE5_H
#define UNSTOPPABLE5_H

#include "../Class/Enemy.h"

class Unstoppable5 : public Enemy {
public:
    Unstoppable5(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Unstoppable5;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable5;
    }

    int getSpeed() const {
        return 250;
    }

    int getWidth() const {
        return 66;
    }
};
#endif