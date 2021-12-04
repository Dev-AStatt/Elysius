#pragma once

#include "libraries/olcPixelGameEngine.h"
#include "engine/graphicsEngine.h"
#include "world/systemsManager.h"

//  0---------------------------------------------------------------------------------------------------0
//  |   The goal of this game will be to complete a Dysonsphere around a planet to supply power to your |
//  |   intersteller ships. Very symple graphics and core mechanics.                                    |
//  0---------------------------------------------------------------------------------------------------0
//

// Override base class with your custom functionality
class ElysiusGameLoop : public olc::PixelGameEngine
{
public:
    ElysiusGameLoop();

    bool OnUserCreate() override;

    bool OnUserUpdate(float fElapsedTime) override;

private:
    std::shared_ptr<GraphicsEngine> graphicsEngine;
    std::unique_ptr<SystemsManager> systemsManager;
};

