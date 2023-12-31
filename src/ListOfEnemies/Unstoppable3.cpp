#include "Unstoppable3.h"

Unstoppable3::Unstoppable3(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Unstoppable3::Unstoppable3(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Unstoppable3::initializeGUI() {
}