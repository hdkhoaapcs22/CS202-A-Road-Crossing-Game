#include "Unstoppable2.h"

Unstoppable2::Unstoppable2(Direction direct, int coordinateXOfEnemy)
: Enemy(direct, coordinateXOfEnemy) {
    initializeGUI();
}
