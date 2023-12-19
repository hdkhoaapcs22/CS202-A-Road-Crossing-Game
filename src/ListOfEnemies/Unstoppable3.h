#ifndef UNSTOPPABLE3_H
#define UNSTOPPABLE3_H

#include "../Class/Enemy.h"

class Unstoppable3 : public Enemy {
public:
    Unstoppable3(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Unstoppable3;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable3;
    }

    int getSpeed() const {
        return 170;
    }

    int getWidth() const {
        return 135;
    }
};
#endif