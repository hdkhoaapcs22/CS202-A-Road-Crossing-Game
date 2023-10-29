#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>

class Enemy {
public:
    void moveEnemy(int direction, float dt);
    enum class EnemyID : int{
        Stoppable1 = 1010,
        Stoppable2 = 2020,
        Stoppable3 = 3030,
        Stoppable4 = 4040,
        Stoppable5 = 505050,
        Unstoppable1 = 1010,
        Unstoppable2 = 2020,
        Unstoppable3 = 3030,
        Unstoppable4 = 4040,
        Unstoppable5 = 5050
    };
    enum class Direction : int{
        LEFT = -1,
        RIGHT = 1
    };
    Enemy(EnemyID id, Direction direct, int coordinateXOfEnemy, const int spped, const int width);
    EnemyID randomEnemyID();
protected:
    //virtual int getSpeed() const = 0;
    //virtual int getWidth() const = 0;
    //virtual EnemyID getEnemyID() const = 0;

private:
    EnemyID id;
    Direction direct;
    int coordinateXOfEnemy;
    int speed;
    int width;
};

#endif
