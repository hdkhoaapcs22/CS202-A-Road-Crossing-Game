#include "Stoppable3.h"

Stoppable3::Stoppable3(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Stoppable3::Stoppable3(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}
