#pragma once
#include <memory>
#include <vector>
#include "world/OrbitalObject.h"
#include "structures/Epos.h"
class SolarSystem {
public:
    SolarSystem() {}
    SolarSystem(const Ei2d& startPos) {
        universePos = startPos;
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::sun, Ei2d(0,0), 20,50));
    }

    void newPlanet(const Ei2d& startPos, const int radius, const int density = 0) {
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::planet, startPos, radius, density));
    }

    const std::unique_ptr<OrbitalObject>& getObjectAt(int i) const { return bodies[i];}
    int getBodyCount() const { return bodies.size(); }

private:
    Ei2d universePos;
    std::vector<std::unique_ptr<OrbitalObject>> bodies;
};
