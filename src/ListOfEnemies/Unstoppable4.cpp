#include "Unstoppable4.h"

Unstoppable4::Unstoppable4(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Unstoppable4::Unstoppable4(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}

void Unstoppable4::initializeGUI() {
}