#pragma once
#include "libraries/olcPixelGameEngine.h"
#include "structures/Epos.h"
#include "devUtilities.h"

class GraphicsEngine {
public:
    GraphicsEngine(olc::PixelGameEngine* p) : pge(p) {
        calcCenterOff();
        utils = std::make_unique<ASU::Utils>();

        //getting decals for the ship
        sprShip = std::make_unique<olc::Sprite>("art/ship.png");
        decShip = std::make_unique<olc::Decal>(sprShip.get());
    }

    void drawBody(Ei2d pos, int radius, olc::Pixel color = olc::WHITE) const;
    void drawOrbit(const Ei2d pos, const int solarRadius) const;
    void drawSpacecraft(const Ei2d& pos, const olc::Pixel color = olc::WHITE) const;
    void setMousePos(const olc::vi2d& mouse) {mousePosition = mouse; }
    void incrementScale() {scale += 1;}
    void decrementScale() {scale -= 1;}


private:
    olc::PixelGameEngine* pge;
    std::unique_ptr<ASU::Utils> utils;
    Ei2d centerOffset;
    olc::vi2d mousePosition = {0,0};
    int scale = 2;
    std::unique_ptr<olc::Sprite> sprShip;
    std::unique_ptr<olc::Decal> decShip;

    void calcCenterOff() {
        centerOffset.x = pge->ScreenHeight() / 2;
        centerOffset.y = pge->ScreenWidth()  / 2;
    }

    void drawString(const std::string s, const olc::vi2d& location);
    const olc::vi2d adjustVi2dToScale(const olc::vi2d& point) const {
        return (point * scale) + utils->ei2dToVi2d(centerOffset);
    }
};
