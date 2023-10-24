#include "Character.h"

#include <iostream>

void Character::moveCharacter(int direction, float dt) {
    switch (direction)
    {
    case MOVE_UP:
        std::cout << "Up\n";
        break;

    case MOVE_DOWN:
        std::cout << "Down\n";
        break;

    case MOVE_LEFT:
        std::cout << "Left\n";
        break;
    
    case MOVE_RIGHT:
        std::cout << "Right\n";
        break;
    
    default:
        break;
    }
}