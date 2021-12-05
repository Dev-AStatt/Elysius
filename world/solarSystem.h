#pragma once
#include <memory>
#include <vector>
#include "world/OrbitalObject.h"
#include "structures/Epos.h"
class SolarSystem {
public:
    SolarSystem(const Ei2d& startPos) : universePos(startPos) {
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::sun,0, 10, 50,BodyColor::yellow));
        newPlanet(40, 5, 20, BodyColor::blue);
        newPlanet(80, 7, 20, BodyColor::red);
    }

    void newPlanet(const int solarRad, const int radius, const int density, BodyColor col) {
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::planet, solarRad, radius, density, col));
    }

    const std::unique_ptr<OrbitalObject>& getObjectAt(int i) const { return bodies[i];}
    int getBodyCount() const { return bodies.size(); }

    void updateSystem(u_int64_t) {
        for(int i = 1; i < (int)bodies.size(); ++i) {
            bodies[i]->updatePos();
        }
    }

private:
    Ei2d universePos;
    std::vector<std::unique_ptr<OrbitalObject>> bodies;
};
