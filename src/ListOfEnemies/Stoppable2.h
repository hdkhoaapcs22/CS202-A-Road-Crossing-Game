#ifndef STOPPABLE2_H
#define STOPPABLE2_H

#include "../Class/Enemy.h"

class Stoppable2 : public Enemy {
public:
    Stoppable2(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Stoppable2;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable2;
    }

    int getSpeed() const {
        return 300;
    }

    int getWidth() const {
        return 100;
    }
};
#endif