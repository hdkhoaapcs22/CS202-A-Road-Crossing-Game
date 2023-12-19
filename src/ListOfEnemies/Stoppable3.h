#ifndef STOPPABLE3_H
#define STOPPABLE3_H

#include "../Class/Enemy.h"

class Stoppable3 : public Enemy {
public:
    Stoppable3(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Stoppable3;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable3;
    }

    int getSpeed() const {
        return 350;
    }

    int getWidth() const {
        return 76;
    }
};
#endif