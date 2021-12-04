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
        if(systemID >= (int)activeSystems.size()) {return;}
        for(int i = 0; i < activeSystems[systemID]->getBodyCount(); ++i) {
            const auto &t = activeSystems[systemID]->getObjectAt(i);
            graphics->drawBody(t->getPos(), t->getRadius());
        }
    }
private:
    std::shared_ptr<GraphicsEngine> graphics;
    std::vector<std::unique_ptr<SolarSystem>> activeSystems;

};
