#include "engine/graphicsEngine.h"

void GraphicsEngine::drawBody(Ei2d pos, int radius, olc::Pixel color) const {
//Center the final position in the center of the screen
    Ei2d finalPos = (pos * scale) + centerOffset;
    radius = radius * scale;
    pge->FillCircle(finalPos.x,finalPos.y,radius, color);
    //if mouse position is within circle draw a hilight around it
    if(utils->ei2dPointInSquare(utils->vi2dToEi2d(mousePosition),finalPos, radius)){
        pge->DrawCircle(finalPos.x,finalPos.y,radius, olc::GREEN);
    }
}


