#include "engine/elysiusGameLoop.h"

int main() {
    ElysiusGameLoop demo;
    if (demo.Construct(1048, 1048, 1, 1))
        demo.Start();
    return 0;
}
