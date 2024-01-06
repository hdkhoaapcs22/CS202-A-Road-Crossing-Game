#include "Unstoppable5.h"

Unstoppable5::Unstoppable5(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Unstoppable5::Unstoppable5(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}
