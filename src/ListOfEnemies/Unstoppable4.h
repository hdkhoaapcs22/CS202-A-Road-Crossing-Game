#ifndef UNSTOPPABLE4_H
#define UNSTOPPABLE4_H

#include "../Class/Enemy.h"

class Unstoppable4 : public Enemy {
public:
    Unstoppable4(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Unstoppable4;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable4;
    }

    int getSpeed() const {
        return 300;
    }

    int getWidth() const {
        return 209;
    }
};
#endif