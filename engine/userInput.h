#pragma once
#include "graphicsEngine.h"
#include "structures/Epos.h"
#include "libraries/olcPixelGameEngine.h"

class UserInput {
public:
    UserInput(olc::PixelGameEngine * p, std::shared_ptr<GraphicsEngine> ge) : pge(p), graphicsEngine(ge) {}

    void updateUserInput() {
        olc::vi2d mousePos = pge->GetMousePos();
        graphicsEngine->setMousePos(mousePos);
        int mouseWheel = pge->GetMouseWheel();
        if(mouseWheel != 0) {
            if(mouseWheel > 0)  { graphicsEngine->incrementScale();}
            if(mouseWheel < 0) { graphicsEngine->decrementScale();}
        }
    }


private:
    olc::PixelGameEngine* pge;
    std::shared_ptr<GraphicsEngine> graphicsEngine;
};
