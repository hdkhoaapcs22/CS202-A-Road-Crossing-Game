#include "Lane.h"

Lane::Lane()
: coordinateYOfLane(0)
, laneName(){};

Lane::Lane(float coordinateYOfLane, LaneName laneName, Biome biome)
: coordinateYOfLane(coordinateYOfLane)
, laneName(laneName)
, biome(biome) {
}

Lane::Lane(LaneName laneName, std::ifstream& input, Biome biome)
: laneName(laneName)
, biome(biome) {
    input >> coordinateYOfLane;
}

void Lane::saveCoordinates(std::ofstream& output) {
    output << coordinateYOfLane << std::endl;
}

float Lane::getCoordinateYOfLane() const {
    return coordinateYOfLane;
}

Lane::LaneName Lane::getLaneName() {
    return laneName;
}

void Lane::move(float deltaY) {
    coordinateYOfLane += deltaY;
}

Texture2D Lane::getBiomeTexture() const {
    switch (biome) {
        case Biome::None:
            return TextureHolder::get(TextureID::RoadLane);
        case Biome::Egypt:
            return TextureHolder::get(TextureID::RoadLaneEgypt);
        case Biome::Ice:
            return TextureHolder::get(TextureID::RoadLaneIce);
        case Biome::Dark:
            return TextureHolder::get(TextureID::RoadLaneDark);
        case Biome::Pirate:
            return TextureHolder::get(TextureID::RoadLanePirate);
    }
    return Texture2D();
}

Lane::Biome Lane::getBiome() const {
    return biome;
}
