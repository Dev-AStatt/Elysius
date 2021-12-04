#pragma once
#include "structures/Epos.h"

enum class BodyType {
    sun,
    planet,
    astroid
};


class OrbitalObject {
public:
    OrbitalObject() {}
    OrbitalObject(const BodyType type,
                  const Ei2d& startPos,
                  const int newDiameter,
                  const int newDensity) {
        solarPos = startPos;
        objectType = type;
        radius = newDiameter;
        density = newDensity;
    }

    void newPos(const Ei2d& np) {solarPos += np;}

    Ei2d getPos()    const { return solarPos;}
    int  getRadius() const { return radius;}
    BodyType getObjectType() const { return objectType;}

private:
    Ei2d solarPos;
    int radius;
    int density;
    BodyType objectType;
};
