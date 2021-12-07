#pragma once
#include <math.h>
#include "structures/Epos.h"

enum class BodyType {
    sun,
    planet,
    moon,
    astroid
};

enum class BodyColor {
    yellow,
    blue,
    red,
    white
};

class OrbitalObject {
public:
    OrbitalObject(const BodyType type, const int solRad, const int newRad,
                  const int newDensity, const int orbiting, const BodyColor col = BodyColor::white) :
                  objectType(type), radius(newRad), solarRadius(solRad),
                  density(newDensity),  orbitingID(orbiting),   color(col){
        angle = rand() % 360;
    }

    Ei2d getPos()      const { return solarPos;}
    int  getAngle()    const { return (int)angle;   }
    int  getDensity()  const { return density; }
    BodyColor getCol() const { return color;   }
    BodyType getObjectType() const { return objectType;}
    int getOrbiting()       const { return orbitingID; }
    int getObjectRadius()   const { return radius;  }
    int getOrbitRadius()    const { return solarRadius;}

    void setAngle(const int a) {angle = (a % 360);}
    void incrementAngle() {
        double adjustment = 1 - (solarRadius/100.0);
        double newAngle = angle + adjustment;

        if(newAngle > 360) { angle = newAngle - 360; }
        angle = newAngle;
    }

    void updatePos(const Ei2d& rotationOrigin) {
        incrementAngle();
        if(objectType == BodyType::sun) {return;}
        double unitx = sin(angle * 3.14 / 180);
        double unity = cos(angle * 3.14 / 180);
        double x = unitx * solarRadius;
        double y = unity * solarRadius;
        solarPos = Ei2d((int)x, (int)y) + rotationOrigin;
   }
private:
    Ei2d solarPos;
    double angle = 0;
    const BodyType objectType;
    const int radius;
    const int solarRadius;
    const int density;
    int orbitingID;
    const BodyColor color;
};
