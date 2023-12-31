#include "Unstoppable1.h"

Unstoppable1::Unstoppable1(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Unstoppable1::Unstoppable1(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Unstoppable1::initializeGUI() {
}