#ifndef LANE_H
#define LANE_H

#include <fstream>
#include "../Config.h"
#include "../gui/ResourceHolders/TextureHolder.h"

#include "raylib.h"

class Lane {
public:
    enum class LaneName {
        RoadLane,
        SafeLane,
        FireLane
    };

    enum class Biome {
        None,
        Egypt,
        Ice,
        Dark,
        Pirate,
    };

    Lane();
    Lane(float coordinateYOfLane, LaneName laneName, Biome biome = Biome::None);
    Lane(LaneName laneName, std::ifstream &input, Biome biome = Biome::None);
    virtual ~Lane() = default;
    void saveCoordinates(std::ofstream &output);
    virtual void save(std::ofstream &output) = 0;

    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    float getCoordinateYOfLane() const;

    LaneName getLaneName();

    void move(float deltaY);

    Texture2D getBiomeTexture() const;

    Biome getBiome() const;

private:
    float coordinateYOfLane;
    LaneName laneName;

    Biome biome;
};

#endif
