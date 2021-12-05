#pragma once
#include "libraries/olcPixelGameEngine.h"
#include "structures/Epos.h"

class GraphicsEngine {
public:
    GraphicsEngine(olc::PixelGameEngine* p) : pge(p) {
        calcCenterOff();
    }

    void drawBody(Ei2d pos, int radius, olc::Pixel color = olc::WHITE) const {
        //Center the final position in the center of the screen
        Ei2d finalPos = pos + centerOffset;
        pge->FillCircle(finalPos.x,finalPos.y,radius, color);
    }


private:
    olc::PixelGameEngine* pge;
    Ei2d centerOffset;

    void calcCenterOff() {
        centerOffset.x = pge->ScreenHeight() / 2;
        centerOffset.y = pge->ScreenWidth()  / 2;
    }
};
