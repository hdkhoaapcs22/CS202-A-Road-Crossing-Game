#ifndef CONFIG_H
#define CONFIG_H

// Singleton class
class Config {
public:
    static constexpr float WINDOW_WIDTH = 1024;
    static constexpr float WINDOW_HEIGHT = 640;
    static constexpr int FPS = 60;
    static constexpr int ENEMY_DISTANCE = 250;
    static constexpr int WIDTH_OF_EACH_CELL = 78;
    static constexpr int FIRST_POSITION_OF_CHARACTER = 507;
    static constexpr int LAST_POSITION_OF_CHARACTER = 975;
    static constexpr int WIDTH_OF_CHARACTER = 40;
    static constexpr float TIME_MOVEMENT = 0.1;
    static constexpr int CELL_IN_LANE = 13;
    static constexpr int NUMBER_OF_LANES = 12;
    static constexpr int SIZE_OF_A_LANE = 78;
    static constexpr int BASE_SPEED = 25;
    static constexpr float ACCERELATED_SPEED = 1;
    static constexpr int CAMERA_OFFSET = 484;

private:
    Config() {
    } // Private constructor to prevent instantiation

    Config(Config const&) = delete;          // Delete copy constructor
    void operator= (Config const&) = delete; // Delete assignment operator
    // Other private member functions and variables here
};

#endif
