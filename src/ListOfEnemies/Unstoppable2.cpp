#include "Unstoppable2.h"

Unstoppable2::Unstoppable2(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Unstoppable2::Unstoppable2(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Unstoppable2::initializeGUI() {
}
