#pragma once
#include "libraries/olcPixelGameEngine.h"
#include "engine/graphicsEngine.h"
#include "world/systemsManager.h"
#include "engine/GameStates.h"

//  0---------------------------------------------------------------------------------------------------0
//  |   The goal of this game will be to complete a Dysonsphere around a planet to supply power to your |
//  |   intersteller ships. Very symple graphics and core mechanics.                                    |
//  0---------------------------------------------------------------------------------------------------0

class ElysiusGameLoop : public olc::PixelGameEngine
{
public:
    ElysiusGameLoop();
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;

private:
    std::shared_ptr<GraphicsEngine> graphicsEngine;
    std::unique_ptr<SystemsManager> systemsManager;
    std::shared_ptr<GameStates> gameStates;


    uint64_t gameTick= 0;
    float accTime = 0;
    bool tickUpdate = false;

    //Functions
    void updateTick(float et);
    void updateUserInput();
};

