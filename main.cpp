#include "engine/elysiusGameLoop.h"

int main() {
    ElysiusGameLoop demo;
    if (demo.Construct(256, 240, 4, 4))
        demo.Start();
    return 0;
}
