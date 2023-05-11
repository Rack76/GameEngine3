#include "../../GameEngine/src/Engine.h"

int main(void)
{
    Engine engine;
    engine.init();
    engine.run();
    engine.terminate();
    //engine.terminate();

    return 0;
}