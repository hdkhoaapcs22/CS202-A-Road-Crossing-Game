#ifndef CONFIG_H
#define CONFIG_H

// Singleton class
class Config {
public:
    static constexpr float WINDOW_WIDTH = 1024;
    static constexpr float WINDOW_HEIGHT = 640;
    static constexpr int FPS = 60;
    static constexpr int ENEMY_DISTANCE = 250;
    static const int WIDTH_OF_EACH_CELL = 78;
    static const int FIRST_POSITION_OF_CHARACTER = 507;
    static const int LAST_POSITION_OF_CHARACTER = 975;
    static const int WIDTH_OF_CHARACTER = 40;
    static const float TIME_MOVEMENT;
    static const int CELL_IN_LANE = 13;
    static const int NUMBER_OF_LANES = 10;
    static const int SIZE_OF_A_LANE = WINDOW_HEIGHT / NUMBER_OF_LANES;
    static const int BASE_SPEED = 25;

private:
    Config() {
    } // Private constructor to prevent instantiation

    Config(Config const&) = delete;          // Delete copy constructor
    void operator= (Config const&) = delete; // Delete assignment operator
    // Other private member functions and variables here
};

#endif
