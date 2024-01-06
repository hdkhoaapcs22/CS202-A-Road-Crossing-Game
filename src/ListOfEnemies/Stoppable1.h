#ifndef STOPPABLE1_H
#define STOPPABLE1_H

#include "../Class/Enemy.h"

class Stoppable1 : public Enemy {
public:
    Stoppable1(Direction direct, int coordinateXOfEnemy);
    Stoppable1(std::ifstream& input);

    TextureID getTextureID() const {
        return TextureID::Stoppable1;
    }

    EnemyID getEnemyID() const {
        return EnemyID::Stoppable1;
    }

    int getSpeed() const {
        return 450;
    }

    int getWidth() const {
        return 226;
    }
};
#endif