#include "engine/graphicsEngine.h"

void GraphicsEngine::drawBody(Ei2d pos, int radius, olc::Pixel color) const {
//Center the final position in the center of the screen
    Ei2d finalPos = (pos * scale) + centerOffset;
    radius = radius * scale;
    pge->FillCircle(finalPos.x,finalPos.y,radius, color);
    //if mouse position is within circle draw a hilight around it
    drawString(vi2dToString(mousePosition), {0,0});
    if(utils->ei2dPointInSquare(utils->vi2dToEi2d(mousePosition),finalPos, radius)){
        pge->DrawCircle(finalPos.x,finalPos.y,radius, olc::GREEN);
    }
}

void GraphicsEngine::drawOrbit(const Ei2d orbitCenterPos,const int solarRadius) const {
    Ei2d finalPos = (orbitCenterPos*scale) + centerOffset;
    int newRadius = solarRadius * scale;
    pge->DrawCircle(finalPos.x,finalPos.y,newRadius,olc::DARK_CYAN);
}


void GraphicsEngine::drawString(const std::string s, const olc::vi2d& location) const {
    pge->DrawStringDecal(location,s);
}

void GraphicsEngine::drawSpacecraft(const Ei2d &pos, const int angle, const olc::Pixel color) const {
    olc::vi2d finalPos = adjustVi2dToScale( utils->ei2dToVi2d(pos));
    float s = scale * 0.03;
    float aRad = (-1) * (angle + 90) * 3.14 / 180;
    //removing this line just for a minute while we use a triangle for a spaceship
    pge->DrawRotatedDecal(finalPos,decShip.get(), aRad + 1.57, {50,50}, {s,s});

}
bool GraphicsEngine::file_exists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

std::string GraphicsEngine::vi2dToString(const olc::vi2d& point) const {
    std::string s = "{ " + std::to_string(point.x) + ", " + std::to_string(point.y) + " }";
    return s;
}
//Wraper for the Draw Rectangle function of OLC
void GraphicsEngine::drawRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const {
    pge->DrawRect(tl.x,tl.y,br.x,br.y, color);
}

//Wraper for the Draw Rectangle function of OLC
void GraphicsEngine::drawFilledRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const {
    pge->FillRect(tl.x,tl.y,br.x,br.y, color);
}



