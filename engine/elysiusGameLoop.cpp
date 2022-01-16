#include "engine/elysiusGameLoop.h"

ElysiusGameLoop::ElysiusGameLoop() {

        // Name your application
        sAppName = "Example";

}

// this will run once on creation of the game itself.
bool ElysiusGameLoop::OnUserCreate() {
    graphicsEngine = std::make_shared<GraphicsEngine>(this);
    systemsManager = std::make_unique<SystemsManager>(graphicsEngine);
    userInput = std::make_unique<UserInput>(this, graphicsEngine);
    //menu = std::make_unique<MenuSystem>(ScreenHeight(), ScreenWidth());
    systemsManager->newSystem(Ei2d(0,0));

    return true;
}

bool ElysiusGameLoop::OnUserUpdate(float fElapsedTime) {
    // Called once per frame
    Clear(olc::BLACK);
    updateTick(fElapsedTime);
    userInput->updateUserInput();
    systemsManager->drawSystem(0);

    return true;
}

void ElysiusGameLoop::updateTick(float et) {
    accTime += et;
    tickUpdate = false;
    if(accTime > (0.016)) {
       accTime = 0;
       gameTick += 1;
       tickUpdate = true;
    }

    //This is where stuff that needs updates go
    if(tickUpdate) {
        systemsManager->updateAll(gameTick);

    }
}








