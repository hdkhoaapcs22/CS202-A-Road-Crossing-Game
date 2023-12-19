#ifndef UNSTOPPABLE2_H
#define UNSTOPPABLE2_H

#include "../Class/Enemy.h"
class Unstoppable2 : public Enemy{
public:
    Unstoppable2(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Unstoppable2;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Unstoppable2;
    }

    int getSpeed() const {
        return 200;
    }

    int getWidth() const {
        return 52;
    }
};
#endif