#pragma once
#include <math.h>
#include "structures/Epos.h"

enum class BodyType {
    sun,
    planet,
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
                  const int newDensity, const BodyColor col = BodyColor::white) :
                  radius(newRad), density(newDensity), objectType(type), color(col), solarRadius(solRad) {
        angle = rand() % 360;
    }

    Ei2d getPos()      const { return solarPos;}
    int  getAngle()    const { return (int)angle;   }
    int  getRadius()   const { return radius;  }
    int  getDensity()  const { return density; }
    BodyColor getCol() const { return color;   }
    BodyType getObjectType() const { return objectType;}

    void setAngle(const int a) {angle = (a % 360);}
    void incrementAngle() {
        double adjustment = 1 - (solarRadius/100.0);
        double newAngle = angle + adjustment;

        if(newAngle > 360) { angle = newAngle - 360; }
        angle = newAngle;
    }

    void updatePos() {
        incrementAngle();
        if(objectType == BodyType::sun) {return;}
        double unitx = sin(angle * 3.14 / 180);
        double unity = cos(angle * 3.14 / 180);
        double x = unitx * solarRadius;
        double y = unity * solarRadius;
        solarPos = {(int)x, (int)y};
   }
private:
    Ei2d solarPos;
    double angle = 0;
    const int radius;
    const int density;
    const BodyType objectType;
    const BodyColor color;
    const int solarRadius;
};
