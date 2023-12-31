#include "Stoppable1.h"

Stoppable1::Stoppable1(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Stoppable1::Stoppable1(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Stoppable1::initializeGUI() {
}