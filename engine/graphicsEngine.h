#pragma once
#include <sys/stat.h>
#include "libraries/olcPixelGameEngine.h"
#include "structures/Epos.h"
#include "devUtilities.h"
#include "menus/Menus.h"
#include "engine/GameStates.h"

class GraphicsEngine {
public:
    GraphicsEngine(olc::PixelGameEngine* p, std::shared_ptr<GameStates>);
    //
    //Drawing Functions
    //
    void drawBody(Ei2d pos, int radius, olc::Pixel color = olc::WHITE) const;
    void drawOrbit(const Ei2d pos, const int solarRadius) const;
    void drawSpacecraft(const Ei2d& pos,const int angle, const olc::Pixel color = olc::WHITE) const;
    void drawActiveMenus() const;
    void drawDebugInfo() const;
    void drawMenuBackground(const Ei2d& topLeft, const Ei2d& widthHight,
                           const olc::Pixel& bgColor, const olc::Pixel& bColor, const int boarderSize) const;

    //
    //Set Functions
    //
    void setMousePos(const olc::vi2d& mouse) {mousePosition = mouse; }
    void incrementScale() {scale += 1;}
    void decrementScale() {scale -= 1;}

    //
    //Requests
    //
    bool askYesNoMenu(std::string s);
    int getScreenHight() const { return pge->ScreenHeight();}
    int getScreenWidth() const { return pge->ScreenWidth() ;}


private:
    //Game display Layers
    int nLayerUI = 0;
    int nLayerGame;

    olc::PixelGameEngine* pge;
    std::unique_ptr<ASU::Utils> utils;
    std::shared_ptr<GameStates> gameStates;
    //Stuff for Menus
    std::vector<std::unique_ptr<Generic_Menu>> activeMenus;
    Ei2d centerOffset;
    olc::vi2d mousePosition = {0,0};
    int scale = 2;
    //Decals
    std::unique_ptr<olc::Sprite> sprShip;
    std::unique_ptr<olc::Decal> decShip;
    std::unique_ptr<olc::Sprite> sprBackground;
    std::unique_ptr<olc::Decal> decBackground;



    bool file_exists(const std::string& name);
    std::string vi2dToString(const olc::vi2d& point) const;
    void drawRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const;
    void drawFilledRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const;
    //basic Draw String
    void drawString(const std::string& s, const olc::vi2d& location) const;
    //Complex Draw String
    void drawString_Ei2d(const std::string& s, const Ei2d& pos, const float scale = 1.0f, const olc::Pixel color = olc::WHITE) const;

    void calcCenterOff() {
        centerOffset.x = pge->ScreenHeight() / 2;
        centerOffset.y = pge->ScreenWidth()  / 2;
    }


    const olc::vi2d adjustVi2dToScale(const olc::vi2d& point) const {
        return (point * scale) + utils->ei2dToVi2d(centerOffset);
    }
};
