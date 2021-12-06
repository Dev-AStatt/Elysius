#pragma once
#include "libraries/olcPixelGameEngine.h"
#include "structures/Epos.h"

//  0-----------------------------------------------0
//  |   Floating Functions for General Utilities    |
//  0-----------------------------------------------0

//ASU ASTATT UTILITIES
namespace ASU {

class Utils {
public:
    olc::vi2d ei2dToVi2d(const Ei2d e) {
        return olc::vi2d(e.x,e.y);
    }

    Ei2d vi2dToEi2d(const olc::vi2d& v) {
        return Ei2d(v.x,v.y);
    }

    bool vi2dPointInSquare(const olc::vi2d& vi2dPoint, const olc::vi2d& SquareCenterPos, const int radius) {
        olc::vi2d topLeft = olc::vi2d(SquareCenterPos.x - radius , SquareCenterPos.y - radius);
        olc::vi2d bottomRight = olc::vi2d(SquareCenterPos.x + radius , SquareCenterPos.y + radius);

        if(topLeft.x <= vi2dPoint.x && bottomRight.x >= vi2dPoint.x) {
            if(topLeft.y <= vi2dPoint.y && bottomRight.y >= vi2dPoint.y) {
                return true;
            }
        }
        return false;
    }

    bool ei2dPointInSquare(const Ei2d ei2dPoint, const Ei2d& squareCenterPos, const int radius) {
        //just call the other written function
        return vi2dPointInSquare(ei2dToVi2d(ei2dPoint), ei2dToVi2d(squareCenterPos), radius);
    }
};
}
