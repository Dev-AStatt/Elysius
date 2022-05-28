#pragma once
#include "graphicsEngine.h"

class MenuStructure {
public:
    MenuStructure(std::shared_ptr<GraphicsEngine> g, int screenHight, int screenWidth) :
        screenH(screenHight) , screenW(screenWidth) {
        graphics = g;
        bottomMenuEnable = true;
    }
    //Make a popup YN box and returns the bool answer to question string
    bool yesNoMenu(const std::string &question);

private:
    std::shared_ptr<GraphicsEngine> graphics;
    int screenH;
    int screenW;
    int bottomMenuEnable = False;

    //Draw the Menu
    void drawMenuWithHeader(const Ei2d& topLeft, const Ei2d& widthHight,
                  std::string header, std::vector<std::string>& options) const;
    //Used by drawMenu, Draws the background
    void drawMenuBackground(const Ei2d& topLeft, const Ei2d& widthHight,
                            const olc::Pixel& bgColor, const olc::Pixel& bColor, int bdSize) const;
    //returns bool if menu points are within the screen hight and width
    bool menuOnScreen(const Ei2d& menuTopLeft, const Ei2d& menuBottomRight) const;
    //Returns true if Ei2d point is within screen H and W
    bool ei2dOnScreen(const Ei2d& p) const;

};








