#include "Stoppable4.h"

Stoppable4::Stoppable4(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}

Stoppable4::Stoppable4(std::ifstream& input)
: Enemy(input) {
    initializeGUI();
}
