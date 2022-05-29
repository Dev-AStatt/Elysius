#include "engine/elysiusGameLoop.h"

ElysiusGameLoop::ElysiusGameLoop() {

        // Name your application
        sAppName = "Example";

}

// this will run once on creation of the game itself.
bool ElysiusGameLoop::OnUserCreate() {
    gameStates = std::make_shared<GameStates>();
    graphicsEngine = std::make_shared<GraphicsEngine>(this, gameStates);
    systemsManager = std::make_unique<SystemsManager>(graphicsEngine);
    systemsManager->newSystem(Ei2d(0,0));


    return true;
}

bool ElysiusGameLoop::OnUserUpdate(float fElapsedTime) {
    // Called once per frame
    Clear(olc::BLACK);
    //Clear any gameState Flags that have been set
    gameStates->clearFlags();

    //check if the game is in "PLAY" and update Tick
    if(gameStates->GameState() == gameStates->gs_play) {
        updateTick(fElapsedTime);
    }
    systemsManager->drawSystem(0);
    graphicsEngine->drawActiveMenus();
    updateUserInput();


    //Debug Information
    graphicsEngine->drawDebugInfo();

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

//Function to handle all of the user keyboard and mouse interactions
void ElysiusGameLoop::updateUserInput() {
    graphicsEngine->setMousePos(GetMousePos());

    //Check if game is in play mode
    if(gameStates->GameState() == gameStates->gs_play) {
        //Mouse Scroll for in and out
        int mouseWheel = GetMouseWheel();
        if(mouseWheel != 0) {
            if(mouseWheel > 0) { graphicsEngine->incrementScale();}
            if(mouseWheel < 0) { graphicsEngine->decrementScale();}
        }
        //Button Presses in Play Mode
        if(GetKey(olc::Key::P).bReleased) { gameStates->setGameState(gameStates->gs_pause);}
        //Pressing q will put up the fist menu
        if(GetKey(olc::Key::Q).bReleased) {

            graphicsEngine->askYesNoMenu("Yes or No?");
        }

    }

    if(gameStates->GameState() == gameStates->gs_pause) {
        if(GetKey(olc::Key::P).bReleased) { gameStates->setGameState(gameStates->gs_play);}

    }

}






