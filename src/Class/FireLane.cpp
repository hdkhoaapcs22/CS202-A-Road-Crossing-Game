#include "FireLane.h"
#include <random>
#include "Config.h"

FireLane::FireLane(float coordinateYOfLane)
: Lane(coordinateYOfLane, Lane::LaneName::FireLane)
, isFire(0)
, fireTime(randomFireTime())
, fireTimer(0)
, fireDuration(Config::TIME_FIRE) {
    initializeGUI();

    update(10 + rand() % 10); // advance forward
}

FireLane::FireLane(std::ifstream& input)
: Lane(Lane::LaneName::FireLane, input) {
    initializeGUI();
    input >> isFire;
    input >> fireTime;
    input >> fireTimer;
    input >> fireDuration;
}

FireLane::~FireLane() {
}

void FireLane::update(float dt) {
    float coordinateYOfLane = getCoordinateYOfLane();

    fireTimer += dt;
    while ((fireTimer >= fireDuration && isFire) || (fireTimer >= fireTime && !isFire)) {
        if (isFire)
            fireTimer -= fireDuration;
        else {
            fireTimer -= fireTime;
            fireTime = randomFireTime();
        }
        isFire = !isFire;
    }

    if (!isFire && fireTime - fireTimer < CHARGE_TIME)
        mObject.update(dt);
    else if (isFire) {
        mObject.restart();
        for (int i = 0; i < 4; i++)
            mAnimations[i].update(dt);
    }
}

void FireLane::draw() {
    float coordinateYOfLane = getCoordinateYOfLane() - Config::SIZE_OF_A_LANE / 2;
    mTexture->setPosition({0, coordinateYOfLane});
    mTexture->draw();
    mObject.draw({0, getCoordinateYOfLane() - 156}, {78, 156});
    if (isFire) {
        for (int i = 0; i < 4; i++)
            mAnimations[i].draw({385.f * i, getCoordinateYOfLane() - 48});
    }
}

bool FireLane::isOnFire() const {
    return isFire;
}

void FireLane::initializeGUI() {
    mTexture = std::make_shared<GUITexture>();
    mTexture->setTexture(TextureHolder::get(TextureID::RoadLane));
    mTexture->setSize({Config::WINDOW_WIDTH, Config::SIZE_OF_A_LANE});

    mObject.setSpriteSheet(TextureHolder::get(TextureID::FireObjectAnim));
    mObject.setRepeating(false);
    mObject.setDuration(CHARGE_TIME);
    mObject.setSpriteSheetGridSize({7, 7});
    mObject.setNumFrames(47);

    for (int i = 0; i < 4; i++) {
        mAnimations.push_back(Animation());
        mAnimations[i].setSpriteSheet(TextureHolder::get(TextureID::FirePatternAnim));
        mAnimations[i].setRepeating(true);
        mAnimations[i].setDuration(0.2);
        mAnimations[i].setSpriteSheetGridSize({2, 2});
        mAnimations[i].setNumFrames(4);
    }
}

void FireLane::save(std::ofstream& output) {
    Lane::saveCoordinates(output);
    output << isFire << std::endl;
    output << fireTime << std::endl;
    output << fireTimer << std::endl;
    output << fireDuration << std::endl;
}

float FireLane::randomFireTime() {
    std::random_device rd;  // Create a random device to seed the generator
    std::mt19937 gen(rd()); // Create a Mersenne Twister pseudo-random number generator
    std::uniform_real_distribution<double> dis(
        7.0, 14.0); // Define a uniform distribution between 3 and 5

    return dis(gen); // Generate and return a random number
}
