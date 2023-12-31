#include "Stoppable5.h"

Stoppable5::Stoppable5(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Stoppable5::Stoppable5(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Stoppable5::initializeGUI() {
}