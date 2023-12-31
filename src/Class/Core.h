#ifndef CORE_H
#define CORE_H

#include <fstream>
#include "../gui/GUIComponents/GUITexture.h"
#include "Character.h"
#include "Map.h"

class Core {
public:
    enum class GameState {
        WaitingToStart,
        Playing,
        Lost
    };

public:
    Core();
    Core(std::ifstream& input);
    float getSpeedMultiplier();
    bool detectCollision();
    bool detectBlockMovement(int direction);

    void update(float dt);
    void draw();

    bool isLost();
    void save(std::ofstream& output);

private:
    int score;
    int virtualScore;
    Map gameMap;
    Character character;

    GameState gameState{GameState::WaitingToStart};

    GUITexture::Ptr scoreFrame;

private:
    void moveCharacter(int direction, float dt);
    void executeMovement(int direction, float dt);
    void getInputs(float dt);

    void drawScore();

    void initializeGUI();
};

#endif
