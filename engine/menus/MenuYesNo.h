#pragma once
#include "devUtilities.h"

class Generic_Menu {
public:
    Generic_Menu() {}
    Generic_Menu(int screenW, int screenH, std::string q) :
        screenHight(screenH), screenWidth(screenW), headerString(q) {}

    //General Fetch Statements
    bool HasHeader()        const {return hasHeader;}
    int BoarderSize()       const {return boarderSize;}
    Ei2d TopLeft_Ei2d()     const {return topLeft_Ei2d;}
    Ei2d WidthHight_Ei2d()  const {return widthHight_Ei2d;}
    Ei2d OptionBoxWH_Ei2d()     const {return optionBoxWH_Ei2d;}
    Ei2d HeaderTopLeft_Ei2d()   const {return headerTopLeft_Ei2d;}
    Ei2d HeaderWH_Ei2d()        const {return headerWH_Ei2d;}
    olc::Pixel BackgroundColor() const {return backgroundColor;}
    olc::Pixel BoarderColor()    const {return boarderColor;}
    olc::Pixel SelectColor()     const {return selectColor;}
    olc::Pixel OptionColor()     const {return optionColor;}
    std::vector<Ei2d> OptionTopLeftPoints() const {return optionTopLeftPoints;}

    //Precompiled Calculations, Run on class construction
    void genMenuPoints() {
        //Calculations on Menu Initialization
        topLeft_Ei2d = Ei2d((screenHight / 2) - (menuHight / 2), (screenWidth / 2) - (menuWidth / 2));
        widthHight_Ei2d = {menuWidth,menuHight};
        //check if points are on screen
        if(!menuOnScreen(topLeft_Ei2d, widthHight_Ei2d)) {return;}

        //Calculate the size of the boxes
        int widthPerItem = widthHight_Ei2d.x - (boarderSize * 4);
        int hightToWorkWith = widthHight_Ei2d.y - boarderSize - (headerHight - headerNegOffset);
        int unusedSpace = (options.size() + 1) * boarderSize;
        int hightPerItem = (hightToWorkWith - unusedSpace) / options.size();
        optionBoxWH_Ei2d = {widthPerItem,hightPerItem};
        //Calculate Header Position
        if(hasHeader) {
            headerTopLeft_Ei2d = topLeft_Ei2d + Ei2d(boarderSize * 2, - headerNegOffset);
            headerWH_Ei2d = {widthPerItem,headerHight};
        }
        //Calculate the TL points of the menu item boxes
        int startingHight = topLeft_Ei2d.y + (headerHight - headerNegOffset);
        for(int i = 0; i < (int)options.size(); ++i) {
            Ei2d temp;
            temp.x = topLeft_Ei2d.x + (boarderSize * 2);
            temp.y = startingHight + boarderSize + (i * (hightPerItem + boarderSize));
            optionTopLeftPoints.emplace_back(temp);
        }


    }
    //returns bool if menu points are within the screen hight and width
    bool menuOnScreen(const Ei2d& menuTopLeft, const Ei2d& menuBottomRight) const {
        if(!ei2dOnScreen(menuTopLeft)) {return false;}
        if(!ei2dOnScreen(menuBottomRight)) {return false;}
        return true;
    }
    //Returns true if Ei2d point is within screen H and W
    bool ei2dOnScreen(const Ei2d& p) const {
        if(p.y <=0 || p.x <=0){return false;}
        if(p.y > screenHight || p.x > screenWidth) {return false;}
        return true;
    }


protected:
    bool active = false;
    bool hasHeader = false;
    int screenHight;
    int screenWidth;
    int menuHight;
    int menuWidth;
    int boarderSize;
    int headerNegOffset = 45;
    int headerHight = 75;
    std::string headerString;
    std::vector<std::string> options;
    std::vector<Ei2d> optionTopLeftPoints;
    Ei2d topLeft_Ei2d;
    Ei2d widthHight_Ei2d;
    Ei2d headerTopLeft_Ei2d;
    Ei2d headerWH_Ei2d;
    Ei2d optionBoxWH_Ei2d;
    olc::Pixel backgroundColor;
    olc::Pixel boarderColor;
    olc::Pixel optionColor;
    olc::Pixel selectColor;

};


class MenuYesNo : public Generic_Menu {
public:
    MenuYesNo(int screenW, int screenH, std::string q) {
        active = true;
        hasHeader = true;
        screenWidth = screenW;
        screenHight = screenH;
        headerString = q;

        // Setup Fields for Menu
        options = {"YES", "NO"};
        menuHight = 250;
        menuWidth = 200;
        boarderSize = 15;
        backgroundColor = olc::Pixel(0,26,51);
        boarderColor = olc::Pixel(18,87,92);
        selectColor = olc::Pixel(155,25,0);
        optionColor = olc::GREEN;


        genMenuPoints();
    }
};
