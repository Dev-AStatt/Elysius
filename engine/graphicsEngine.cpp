#include "engine/graphicsEngine.h"

//  0-------------0
//  |   PUBLIC    |
//  0-------------0

//Constructor
GraphicsEngine::GraphicsEngine(olc::PixelGameEngine* p, std::shared_ptr<GameStates> gs) : pge(p), gameStates(gs) {
    calcCenterOff();
    utils = std::make_unique<ASU::Utils>();

    //getting decals for the ship
    std::string spaceship_file_name = "art/ship.png";
    if(!file_exists(spaceship_file_name)) {
        throw std::invalid_argument( "Cannot find spaceship file" );
    }
    sprShip = std::make_unique<olc::Sprite>(spaceship_file_name);
    decShip = std::make_unique<olc::Decal>(sprShip.get());

}


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

void GraphicsEngine::drawOrbit(const Ei2d orbitCenterPos,const int solarRadius) const {
    Ei2d finalPos = (orbitCenterPos*scale) + centerOffset;
    int newRadius = solarRadius * scale;
    pge->DrawCircle(finalPos.x,finalPos.y,newRadius,olc::DARK_CYAN);
}

void GraphicsEngine::drawSpacecraft(const Ei2d &pos, const int angle, const olc::Pixel color) const {
    olc::vi2d finalPos = adjustVi2dToScale( utils->ei2dToVi2d(pos));
    float s = scale * 0.03;
    float aRad = (-1) * (angle + 90) * 3.14 / 180;
    //removing this line just for a minute while we use a triangle for a spaceship
    pge->DrawRotatedDecal(finalPos,decShip.get(), aRad + 1.57, {50,50}, {s,s});

}

//Wraper for the Draw Rectangle function of OLC
void GraphicsEngine::drawRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const {
    pge->DrawRect(tl.x,tl.y,br.x,br.y, color);
}

//Wraper for the Draw Rectangle function of OLC
void GraphicsEngine::drawFilledRect(const Ei2d tl, const Ei2d br, olc::Pixel color) const {
    pge->FillRect(tl.x,tl.y,br.x,br.y, color);
}

//Creates and Draws a yes no menu, returns answer
bool GraphicsEngine::askYesNoMenu(std::string s) {
    //puase the game because we are putting up a menu
    gameStates->setGameState(gameStates->gs_pause);
    //add the menu
    activeMenus.emplace_back(std::make_unique<MenuYesNo>(getScreenWidth(),getScreenHight(),s));
    return true;
}

///
/// Drawing Menu Functions
///

//Function will draw all the active menus stored in activeMenus vector to the screen
void GraphicsEngine::drawActiveMenus() const {
    //check if there are any menus active
    if(activeMenus.size() <= 0) {return;}

    for(int i = 0; i < (int)activeMenus.size(); ++i) {
        //Draw background
        drawMenuBackground(activeMenus[i]->TopLeft_Ei2d(),
                           activeMenus[i]->WidthHight_Ei2d(),
                           activeMenus[i]->BackgroundColor(),
                           activeMenus[i]->BoarderColor(),
                           activeMenus[i]->BoarderSize());
        //Check for Mouse Focus
        Ei2d mousePos = utils->vi2dToEi2d(pge->GetMousePos());
        //if mouse is within menu, set mouse focus to mf_menu
        //if mouse is out of menu, set mouse focus to mf_game
        if(utils->ei2dPointInRect(mousePos, activeMenus[i]->TopLeft_Ei2d(), activeMenus[i]->WidthHight_Ei2d())) {
            gameStates->setMouseFocus(gameStates->mf_menu);
        } else {gameStates->setMouseFocus(gameStates->mf_game);}

        //Draw Header if has one
        if(activeMenus[i]->HasHeader()) {
            //Draw Box
            drawFilledRect(activeMenus[i]->HeaderTopLeft_Ei2d(),
                           activeMenus[i]->HeaderWH_Ei2d(),
                           activeMenus[i]->BoarderColor());
            //Draw String
            drawString_Ei2d(activeMenus[i]->HeaderString(),
                            activeMenus[i]->HeaderTextPos_Ei2d(),
                            activeMenus[i]->TextScale(),
                            activeMenus[i]->TextColor());

        }

        std::vector<Ei2d> optionPoints = activeMenus[i]->OptionTopLeftPoints();
        //Loop through Menu Items
        for(int p = 0; p < (int)optionPoints.size(); ++p) {
            //Check Mouse Colision
            if(utils->ei2dPointInRect(mousePos, optionPoints[p], activeMenus[i]->OptionBoxWH_Ei2d())) {
                //Draw Menu Items
                drawFilledRect(optionPoints[p],
                               activeMenus[i]->OptionBoxWH_Ei2d(),
                               activeMenus[i]->SelectColor());
            } else {
                //Draw Menu Items
                drawFilledRect(optionPoints[p],
                               activeMenus[i]->OptionBoxWH_Ei2d(),
                               activeMenus[i]->OptionColor());
            }
            //Draw Menu Item String
            drawString_Ei2d(activeMenus[i]->OptionStr(p),
                            optionPoints[p] + activeMenus[i]->OptionBoxTextOffset(),
                            activeMenus[i]->TextScale(),
                            activeMenus[i]->TextColor());

        } //Closes loop through menu items loop
    } //Closes loop through active menus
}

//
// Function takes the same size inputs as drawMenu, with two added colors that are used
// for the boarder and background colors. adjustable size of the menu boarders
//
void GraphicsEngine::drawMenuBackground(const Ei2d& topLeft, const Ei2d& widthHight,
                                       const olc::Pixel& bgColor, const olc::Pixel& bColor, const int boarderSize) const {
    //backgroud of text box
    drawFilledRect(topLeft,widthHight,bgColor);
    //Boarder of box, top, left, right, bottom
    drawFilledRect(topLeft, Ei2d(widthHight.x,boarderSize),bColor);
    drawFilledRect(topLeft, Ei2d(boarderSize,widthHight.y),bColor);
    drawFilledRect(Ei2d(topLeft.x + widthHight.x - boarderSize,topLeft.y), Ei2d(boarderSize,widthHight.y),bColor);
    drawFilledRect(Ei2d(topLeft.x,topLeft.y + widthHight.y - boarderSize), Ei2d(widthHight.x,boarderSize),bColor);
}

void GraphicsEngine::drawDebugInfo() const {
    drawString(vi2dToString(mousePosition), {0,0});

    //GameState and Menu Focus
    drawString("Game State: " + std::to_string(gameStates->GameState()),  {0,10});
    drawString("Menu Focus: " + std::to_string(gameStates->MouseFocus()), {0,20});
}


//  0-------------0
//  |   PRIVATE   |
//  0-------------0

void GraphicsEngine::drawString(const std::string &s, const olc::vi2d& location) const {
    pge->DrawStringDecal(location,s);
}

void GraphicsEngine::drawString_Ei2d(const std::string &s, const Ei2d &pos, const float scale, const olc::Pixel color) const {
    pge->DrawStringDecal(utils->ei2dToVi2d(pos), s, color, olc::vf2d(scale,scale));
}


bool GraphicsEngine::file_exists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

std::string GraphicsEngine::vi2dToString(const olc::vi2d& point) const {
    std::string s = "{ " + std::to_string(point.x) + ", " + std::to_string(point.y) + " }";
    return s;
}




