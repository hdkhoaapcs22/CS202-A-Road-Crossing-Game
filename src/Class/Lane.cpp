#include "Lane.h"

Lane::Lane()
: coordinateYOfLane(0)
, saveID("")
, laneName(){};

Lane::Lane(int coordinateYOfLane)
: coordinateYOfLane(coordinateYOfLane)
, saveID("")
, laneName(){};

Lane::Lane(int coordinateYOfLane, LaneName laneName)
: coordinateYOfLane(coordinateYOfLane)
, saveID("")
, laneName(laneName){};
