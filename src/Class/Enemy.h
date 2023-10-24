#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    void moveEnemy(int direction, float dt);
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
        Unstoppable5
    };

protected:
    virtual int getSpeed() const = 0;
    virtual int getWidth() const = 0;
    virtual EnemyID getEnemyID() const = 0;

private:
    int coordinateXOfEnemy;
    const int speed;
    const int width;
};

#endif
