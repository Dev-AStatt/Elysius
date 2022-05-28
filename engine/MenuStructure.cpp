#pragma once
#include "engine/MenuStructure.h"

//  0-------------0
//  |   PUBLIC    |
//  0-------------0

bool MenuStructure::yesNoMenu(const std::string& question) {
    std::vector<std::string> answers = {"YES", "NO"};
    //Calculate how big the box should be
    int strLength = question.length();
    int menuH = 300;
    int menuW = strLength * 25;
    //Calculate where the corner should be
    int menuT = (screenH / 2) - (menuH / 2);
    int menuL = (screenW / 2) - (menuW / 2);

    Ei2d menuTL = {menuT,menuL};
    Ei2d menuWH = Ei2d(menuW,menuH);

    drawMenuWithHeader(menuTL,menuWH, question, answers);
}

//  0-------------0
//  |   PRIVATE   |
//  0-------------0

//draw menu takes the menu structured by the class, and gives it to the graphics
//engine to draw.
void MenuStructure::drawMenuWithHeader(const Ei2d& topLeft, const Ei2d& widthHight,
                             std::string header, std::vector<std::string>& options) const {
    //Check menu will be on screen
    if(!menuOnScreen(topLeft,widthHight)){return;}

    //COLORS
    olc::Pixel menuBackground = olc::DARK_GREY;
    olc::Pixel menuBoarder    = olc::DARK_BLUE;
    //Boarder Size
    int boarderSize = 15;

    //Draw background
    drawMenuBackground(topLeft, widthHight, menuBackground,menuBoarder, boarderSize);


    //Find how many boxes we need
    int menuItems = 1 + options.size();
    int hightPerItem = ((widthHight.y - (boarderSize * 4)) / menuItems);
    int widthPerItem = widthHight.x - (boarderSize * 4);

    //Draw Boxes for Items
    Ei2d posOfBox;
    for(int i = 0; i < menuItems; ++i) {
        int itOffset = i * (hightPerItem + boarderSize);
        posOfBox = topLeft + Ei2d(boarderSize * 2, (boarderSize * 2) + itOffset);
        graphics->drawFilledRect(posOfBox, {widthPerItem,hightPerItem},menuBoarder);

    }
}

//
// Function takes the same size inputs as drawMenu, with two added colors that are used
// for the boarder and background colors. adjustable size of the menu boarders
//
void MenuStructure::drawMenuBackground(const Ei2d& topLeft, const Ei2d& widthHight,
                                       const olc::Pixel& bgColor, const olc::Pixel& bColor, int boarderSize) const {
    //backgroud of text box
    graphics->drawFilledRect(topLeft,widthHight,bgColor);
    //Boarder of box, top, left, right, bottom
    graphics->drawFilledRect(topLeft, Ei2d(widthHight.x,boarderSize),bColor);
    graphics->drawFilledRect(topLeft, Ei2d(boarderSize,widthHight.y),bColor);
    graphics->drawFilledRect(Ei2d(topLeft.x + widthHight.x - boarderSize,topLeft.y), Ei2d(boarderSize,widthHight.y),bColor);
    graphics->drawFilledRect(Ei2d(topLeft.x,topLeft.y + widthHight.y - boarderSize), Ei2d(widthHight.x,boarderSize),bColor);



}

//returns bool if menu points are within the screen hight and width
bool MenuStructure::menuOnScreen(const Ei2d& menuTopLeft, const Ei2d& menuBottomRight) const {
    if(!ei2dOnScreen(menuTopLeft)) {return false;}
    if(!ei2dOnScreen(menuBottomRight)) {return false;}
    return true;
}
//Returns true if Ei2d point is within screen H and W
bool MenuStructure::ei2dOnScreen(const Ei2d& p) const {
    if(p.y <=0 || p.x <=0){return false;}
    if(p.y > screenH || p.x > screenW){return false;}
    return true;
}
