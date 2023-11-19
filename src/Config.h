#ifndef CONFIG_H
#define CONFIG_H

// Singleton class
class Config {
public:
    static constexpr float WINDOW_WIDTH = 1024;
    static constexpr float WINDOW_HEIGHT = 640;
    static constexpr int FPS = 60;
    static constexpr int ENEMY_DISTANCE = 250;

private:
    Config() {
    } // Private constructor to prevent instantiation

    Config(Config const&) = delete;          // Delete copy constructor
    void operator= (Config const&) = delete; // Delete assignment operator
    // Other private member functions and variables here
};

#endif
