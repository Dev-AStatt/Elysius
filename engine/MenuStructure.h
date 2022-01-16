#pragma once
#include "graphicsEngine.h"

class MenuStructure {
public:
    MenuStructure(std::shared_ptr<GraphicsEngine> g, int screenHight, int screenWidth) :
        screenH(screenHight) , screenW(screenWidth) {
        graphics = g;
        bottomMenuEnable = true;
    }

    void drawBottomMenu() {
        if(!bottomMenuEnable) { return; }
       int bottomMenuHight = screenH / 10;


       //calling Drawings

    }

private:
    std::shared_ptr<GraphicsEngine> graphics;
    int screenH;
    int screenW;
    int bottomMenuEnable = False;


};

