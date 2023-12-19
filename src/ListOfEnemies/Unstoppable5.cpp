#include "Unstoppable5.h"

Unstoppable5::Unstoppable5(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}