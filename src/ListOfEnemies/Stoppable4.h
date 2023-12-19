#ifndef STOPPABLE4_H
#define STOPPABLE4_H

#include "../Class/Enemy.h"

class Stoppable4 : public Enemy {
public:
    Stoppable4(Direction direct, int coordinateXOfEnemy);

    TextureID getTextureID() const {
        return TextureID::Stoppable4;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable4;
    }

    int getSpeed() const {
        return 300;
    }

    int getWidth() const {
        return 134;
    }
};
#endif