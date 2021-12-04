#include "engine/elysiusGameLoop.h"

ElysiusGameLoop::ElysiusGameLoop() {

        // Name your application
        sAppName = "Example";

}

// this will run once on creation of the game itself.
bool ElysiusGameLoop::OnUserCreate() {
    graphicsEngine = std::make_shared<GraphicsEngine>(this);
        return true;
}

bool ElysiusGameLoop::OnUserUpdate(float fElapsedTime) {
    // Called once per frame
    Clear(olc::BLACK);
    for (int x = 0; x < ScreenWidth(); x++)
        for (int y = 0; y < ScreenHeight(); y++)
            graphicsEngine->drawPixel(x,y);
    return true;
}

