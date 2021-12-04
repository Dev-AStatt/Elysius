#pragma once

#include "libraries/olcPixelGameEngine.h"

class GraphicsEngine {
public:
    GraphicsEngine() {}
    GraphicsEngine(olc::PixelGameEngine* p) {
        pge = p;
    }
    void drawPixel(int x, int y) {
        pge->Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));

    }

private:
    olc::PixelGameEngine* pge;
};
