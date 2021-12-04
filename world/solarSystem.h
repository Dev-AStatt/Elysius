#pragma once
#include "world/planet.h"
#include "structures/Epos.h"
class SolarSystem {
public:
    SolarSystem() {}
    SolarSystem(Ei2d& startPos) {
        universePos = startPos;
    }

private:
    Ei2d universePos;
};
