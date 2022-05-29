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
    //Converts a Ei2d point to a Vi2d point
    olc::vi2d ei2dToVi2d(const Ei2d e) {return olc::vi2d(e.x,e.y);}
    //Converts a Vi2d point to a Ei2d point
    Ei2d vi2dToEi2d(const olc::vi2d& v) {return Ei2d(v.x,v.y);}
    //Checks if a Vi2d point is within a square, given the center point and a "Radius"
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
    //Checks if a Ei2d point is within a square, given the center point and a "Radius"
    bool ei2dPointInSquare(const Ei2d ei2dPoint, const Ei2d& squareCenterPos, const int radius) {
        //just call the other written function
        return vi2dPointInSquare(ei2dToVi2d(ei2dPoint), ei2dToVi2d(squareCenterPos), radius);
    }
    //Function returns true if Ei2d point is [inclusive] within the rectangle bound by rectTL (Top left of box)
    //and hight width of the box.
    bool ei2dPointInRect(const Ei2d ei2dPoint, const Ei2d& rectTL, const Ei2d& widthHight) const {
        if(rectTL.x <= ei2dPoint.x && ei2dPoint.x <= (rectTL.x + widthHight.x)) {
            if(rectTL.y <= ei2dPoint.y && ei2dPoint.y <= (rectTL.y + widthHight.y)) {
                return true;
            }
        }
        return false;
    }

};
}
