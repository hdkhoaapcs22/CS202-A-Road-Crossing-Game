#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "raylib.h"

#include "../Config.h"
#include "../gui/GUIComponents/GUITexture.h"

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
    Enemy(Direction direct, float coordinateXOfEnemy);
    Enemy(std::ifstream& input);
    void save(std::ofstream& output);
    void moveEnemy(float dt);
    virtual int getSpeed() const = 0;
    virtual int getWidth() const = 0;
    virtual EnemyID getEnemyID() const = 0;
    virtual TextureID getTextureID() const = 0;

    float getCoordinateXOfEnemy();
    void setCoordinateXOfEnemy(float coordinateX);
    bool checkCollision(int leftHitbox, int rightHitbox);

    void draw(float coordinateYOfLane);

protected:
    void initializeGUI();

private:
    Direction direct;
    float coordinateX;
    
    GUITexture::Ptr mTexture;
};

#endif
