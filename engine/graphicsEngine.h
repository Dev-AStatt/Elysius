#pragma once
#include "libraries/olcPixelGameEngine.h"
#include "structures/Epos.h"

class GraphicsEngine {
public:
    GraphicsEngine() {}
    GraphicsEngine(olc::PixelGameEngine* p) {
        pge = p;
        calcCenterOff();
    }

    void drawBody(Ei2d pos, int radius) const {
        Ei2d finalPos = pos + centerOffset;

        pge->FillCircle(finalPos.x,finalPos.y,radius);
    }


private:
    olc::PixelGameEngine* pge;
    Ei2d centerOffset;

    void calcCenterOff() {
        centerOffset.x = pge->ScreenHeight() / 2;
        centerOffset.y = pge->ScreenWidth()  / 2;
    }
};
