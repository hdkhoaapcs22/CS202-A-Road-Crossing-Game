#include "FireLane.h"
#include <random>
#include "Config.h"

FireLane::FireLane(float coordinateYOfLane)
: Lane(coordinateYOfLane, Lane::LaneName::FireLane)
, isFire(0)
, fireTime(randomFireTime())
, fireTimer(0)
, fireDuration(Config::TIME_FIRE) {
}

FireLane::~FireLane() {
}

void FireLane::update(float dt) {
    float coordinateYOfLane = getCoordinateYOfLane();

    fireTimer += dt;
    while (fireTimer >= fireDuration | fireTimer >= fireTime) {
        if (isFire)
            fireTimer -= fireDuration;
        else
            fireTimer -= fireTime;
        isFire = !isFire;
    }
}

void FireLane::draw() {
}

float FireLane::randomFireTime() {
    std::random_device rd;  // Create a random device to seed the generator
    std::mt19937 gen(rd()); // Create a Mersenne Twister pseudo-random number generator
    std::uniform_real_distribution<double> dis(
        3.0, 5.0); // Define a uniform distribution between 3 and 5

    return dis(gen); // Generate and return a random number
}
