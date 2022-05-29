#pragma once
#include <sys/stat.h>
#include "libraries/olcPixelGameEngine.h"
#include "structures/Epos.h"
#include "devUtilities.h"
#include "menus/MenuYesNo.h"

class GraphicsEngine {
public:
    GraphicsEngine(olc::PixelGameEngine* p);

    void drawBody(Ei2d pos, int radius, olc::Pixel color = olc::WHITE) const;
    void drawOrbit(const Ei2d pos, const int solarRadius) const;
    void drawSpacecraft(const Ei2d& pos,const int angle, const olc::Pixel color = olc::WHITE) const;
    void setMousePos(const olc::vi2d& mouse) {mousePosition = mouse; }
    void incrementScale() {scale += 1;}
    void decrementScale() {scale -= 1;}
    void drawRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const;
    void drawFilledRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const;

    bool askYesNoMenu(std::string s);

    int getScreenHight() const { return pge->ScreenHeight();}
    int getScreenWidth() const { return pge->ScreenWidth() ;}


    void drawActiveMenus() const;
    void drawMenuBackground(const Ei2d& topLeft, const Ei2d& widthHight,
                            const olc::Pixel& bgColor, const olc::Pixel& bColor, const int boarderSize) const;
private:
    olc::PixelGameEngine* pge;
    std::unique_ptr<ASU::Utils> utils;
    //Stuff for Menus
    std::vector<std::unique_ptr<Generic_Menu>> activeMenus;
    Ei2d centerOffset;
    olc::vi2d mousePosition = {0,0};
    int scale = 2;
    std::unique_ptr<olc::Sprite> sprShip;
    std::unique_ptr<olc::Decal> decShip;



    bool file_exists(const std::string& name);
    std::string vi2dToString(const olc::vi2d& point) const;
    void drawString(const std::string s, const olc::vi2d& location) const;
    void calcCenterOff() {
        centerOffset.x = pge->ScreenHeight() / 2;
        centerOffset.y = pge->ScreenWidth()  / 2;
    }


    const olc::vi2d adjustVi2dToScale(const olc::vi2d& point) const {
        return (point * scale) + utils->ei2dToVi2d(centerOffset);
    }
};
