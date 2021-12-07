#pragma once
#include "structures/Epos.h"

class Spacecraft {
public:

    Ei2d getPos()           const {return solarPos;}
    int getOrbitAngle()     const {return orbitAngle;}
    int getObitingBodyID()  const {return orbitingBodyID; }
    std::string getName()   const {return name;}

    void updateOrbitPos(const Ei2d& rotationOrigin) {
        if(!inOrbit) {return;}
        incrementAngle();
        double unitx = sin(orbitAngle * 3.14 / 180);
        double unity = cos(orbitAngle * 3.14 / 180);
        double x = unitx * orbitalRadius;
        double y = unity * orbitalRadius;
        solarPos = Ei2d((int)x, (int)y) + rotationOrigin;
   }


private:
    bool inOrbit;
    Ei2d solarPos;
    double orbitAngle;
    int orbitalRadius;
    int orbitingBodyID;
    const std::string name;

    void incrementAngle() {
        double adjustment = 1 - (orbitalRadius/100.0);
        double newAngle = orbitAngle + adjustment;

        if(newAngle > 360) { orbitAngle = newAngle - 360; }
        orbitAngle = newAngle;
    }
};
