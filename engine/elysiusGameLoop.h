#pragma once

#include "libraries/olcPixelGameEngine.h"
#include "engine/graphicsEngine.h"

// Override base class with your custom functionality
class ElysiusGameLoop : public olc::PixelGameEngine
{
public:
    ElysiusGameLoop();

public:
    bool OnUserCreate() override;

    bool OnUserUpdate(float fElapsedTime) override;

private:
    std::shared_ptr<GraphicsEngine> graphicsEngine;
};

