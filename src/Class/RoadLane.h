#ifndef ROAD_LANE_H
#define ROAD_LANE_H

#include <deque>
#include <fstream>
#include "../Config.h"
#include "../ListOfEnemies/Stoppable1.h"
#include "../ListOfEnemies/Stoppable2.h"
#include "../ListOfEnemies/Stoppable3.h"
#include "../ListOfEnemies/Stoppable4.h"
#include "../ListOfEnemies/Stoppable5.h"
#include "../ListOfEnemies/Unstoppable1.h"
#include "../ListOfEnemies/Unstoppable2.h"
#include "../ListOfEnemies/Unstoppable3.h"
#include "../ListOfEnemies/Unstoppable4.h"
#include "../ListOfEnemies/Unstoppable5.h"
#include "Lane.h"

#include "../gui/GUIComponents/GUITexture.h"
#include "../gui/Animation.h"

class RoadLane : public Lane {
public:
    RoadLane(Enemy::EnemyID enemyID, float coordinateYOfLane, Biome biome = Biome::None);
    RoadLane(std::ifstream &input, Biome biome = Biome::None);
    void save(std::ofstream &output) override;
    void update(float dt) override;
    void draw() override;
    ~RoadLane();
    bool checkCollision(int leftHitbox, int rightHitbox);

private:
    static constexpr float BREAK_TIME = 5;
    bool hasTrafficLight;
    bool isRedSignal;
    float breakTimer;
    float spawnTimer;
    float spawnTime;
    Direction direct;
    Enemy::EnemyID enemyID;
    std::deque<Enemy *> enemies;

    GUITexture::Ptr mTexture;
    Animation mTrafficLightAnimation;

private:
    void createEnemy(Enemy::EnemyID enemyID, float startingX);
    void deleteEnemiesBack();
    void checkHasTrafficLight();
    void manageTraffic(float dt);
    void manageEnemies(Enemy *enemy);

    void initializeGUI();
};

#endif
