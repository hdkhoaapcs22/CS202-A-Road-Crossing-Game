#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>

enum class Direction : int {
    Left = -1,
    Right = 1
};

class Enemy {
public:
    enum class EnemyID {
        Stoppable1,
        Stoppable2,
        Stoppable3,
        Stoppable4,
        Stoppable5,
        Unstoppable1,
        Unstoppable2,
        Unstoppable3,
        Unstoppable4,
        Unstoppable5,
    };
    Enemy(Direction direct, int coordinateXOfEnemy);
    void moveEnemy(float dt);
    virtual int getSpeed() const = 0;
    virtual int getWidth() const = 0;
    virtual EnemyID getEnemyID() const = 0;
    int getCoordinateXOfEnemy();
    bool checkCollision(int leftHitbox, int rightHitbox);

private:
    Direction direct;
    int coordinateX;
};

#endif
