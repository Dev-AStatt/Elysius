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

private:
    std::shared_ptr<GraphicsEngine> graphics;
    std::vector<SolarSystem> activeSystems;

};
