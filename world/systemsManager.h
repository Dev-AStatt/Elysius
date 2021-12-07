#pragma once
#include <memory>
#include "world/solarSystem.h"
#include "engine/graphicsEngine.h"

class SystemsManager {
public:
    SystemsManager() {}
    SystemsManager(std::shared_ptr<GraphicsEngine> ge) {
        graphics = ge;
    }

    void newSystem(const Ei2d& startPos) {
        activeSystems.emplace_back(std::make_unique<SolarSystem>(startPos));
    }

    void drawSystem(int systemID) const {
        //check if system to draw is in vector active System
        if(systemID >= (int)activeSystems.size()) {return;}
        //draw all objects in system
        for(int i = 0; i < activeSystems[systemID]->getBodyCount(); ++i) {
            //with system
            const auto &t = activeSystems[systemID]->getObjectAt(i);

            //get the object that t is orbiting from the solar system
            auto &orbiting = activeSystems[systemID]->getObjectAt(t->getOrbiting());
            //draw ring of orbit
            graphics->drawOrbit(orbiting->getPos(),t->getOrbitRadius());
            //draw body
            graphics->drawBody(t->getPos(), t->getObjectRadius(), convertColToOLC(t->getCol()));
        }
    }

    void updateAll(uint64_t currentTick) {
        if(currentTick % 2 != 0) { return; }
        for(int i = 0; i < (int)activeSystems.size(); ++i) {
            activeSystems[i]->updateSystem(currentTick);
        }
    }

private:
    std::shared_ptr<GraphicsEngine> graphics;
    std::vector<std::unique_ptr<SolarSystem>> activeSystems;


    olc::Pixel convertColToOLC(const BodyColor col) const {
        if(col == BodyColor::yellow) {return olc::YELLOW;}
        if(col == BodyColor::blue  ) {return olc::BLUE;  }
        if(col == BodyColor::red   ) {return olc::RED;   }
        else { return olc::WHITE;}
    }
};
