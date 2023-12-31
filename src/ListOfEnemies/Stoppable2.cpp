#include "Stoppable2.h"

Stoppable2::Stoppable2(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Stoppable2::Stoppable2(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Stoppable2::initializeGUI() {
}