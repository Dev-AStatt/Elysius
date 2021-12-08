#pragma once
#include "structures/Epos.h"

class Spacecraft {
public:

    Spacecraft(const int solSysID, const bool inOrb,const int orbitBody, const int orbitRad, const Ei2d& startPos) :
        solarSystemID(solSysID), inOrbit(inOrb), orbitBodyID(orbitBody), orbitRadius(orbitRad), solarPos(startPos) {

    }

    Ei2d getPos()           const {return solarPos;}
    int getOrbitAngle()     const {return orbitAngle;}
    int getObitingBodyID()  const {return orbitBodyID; }
    std::string getName()   const {return name;}
    int getSolarSystem()    const {return solarSystemID;}

    void updateOrbitPos(const Ei2d& rotationOrigin) {
        if(!inOrbit) {return;}
        incrementAngle();
        double unitx = sin(orbitAngle * 3.14 / 180);
        double unity = cos(orbitAngle * 3.14 / 180);
        double x = unitx * orbitRadius;
        double y = unity * orbitRadius;
        solarPos = Ei2d((int)x, (int)y) + rotationOrigin;
   }


private:
    int solarSystemID;
    bool inOrbit;
    int orbitBodyID;
    double orbitAngle;
    int orbitRadius;
    Ei2d solarPos;
    const std::string name;

    void incrementAngle() {
        double adjustment = 1 - (orbitRadius/100.0);
        double newAngle = orbitAngle + adjustment;

        if(newAngle > 360) { orbitAngle = newAngle - 360; }
        orbitAngle = newAngle;
    }
};
