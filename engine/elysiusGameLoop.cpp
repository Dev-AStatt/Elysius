#include "engine/elysiusGameLoop.h"

ElysiusGameLoop::ElysiusGameLoop() {

        // Name your application
        sAppName = "Example";

}

// this will run once on creation of the game itself.
bool ElysiusGameLoop::OnUserCreate() {
    graphicsEngine = std::make_shared<GraphicsEngine>(this);
    systemsManager = std::make_unique<SystemsManager>(graphicsEngine);

    systemsManager->newSystem(Ei2d(0,0));

    return true;
}

bool ElysiusGameLoop::OnUserUpdate(float fElapsedTime) {
    // Called once per frame
    Clear(olc::BLACK);

    systemsManager->drawSystem(0);

    return true;
}

