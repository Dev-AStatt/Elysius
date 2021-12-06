#pragma once
#include <memory>
#include <vector>
#include "world/OrbitalObject.h"
#include "structures/Epos.h"
class SolarSystem {
public:
    SolarSystem(const Ei2d& startPos) : universePos(startPos) {
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::sun,0, 10, 50,0,BodyColor::yellow));
        newPlanet(40, 5, 20, BodyColor::blue);
        newPlanet(80, 7, 20, BodyColor::red);
        newMoon(15,2,20,2, BodyColor::white);
        newMoon(30,2,20,2, BodyColor::white);
    }


    const std::unique_ptr<OrbitalObject>& getObjectAt(int i) const { return bodies[i];}
    int getBodyCount() const { return bodies.size(); }

    void updateSystem(u_int64_t) {
        for(int i = 1; i < (int)bodies.size(); ++i) {
            switch (bodies[i]->getObjectType()) {
                case BodyType::planet :
                    //planets orbit the sun ID 0. get position of the sun and pass to planet
                    bodies[i]->updatePos(bodies[0]->getPos());
                break;

                case BodyType::moon :
                    // ask the body[i] for the id of its orbit planet and then ask the orbit planet
                    // what its position is, then give that position to updatePos()
                    bodies[i]->updatePos(bodies[bodies[i]->getOrbiting()]->getPos());
                break;

                default:

                break;

            }
        }
    }

private:
    Ei2d universePos;
    std::vector<std::unique_ptr<OrbitalObject>> bodies;

    void newPlanet(const int solarRad, const int radius, const int density, BodyColor col) {
        //the zero at the end is because all planets orbit the sun, ID 0
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::planet, solarRad, radius, density,0 ,col));
    }

    void newMoon(const int solarRad, const int radius, const int density, int bodyID, BodyColor col) {
        bodies.emplace_back(std::make_unique<OrbitalObject>(BodyType::moon, solarRad, radius, density, bodyID, col));
    }
};
