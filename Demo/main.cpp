#include "../GameEngine/src/Engine.h"

int main(void)
{

    /* Initialize the library */
    Engine engine;
    engine.init();
    engine.run();
    //engine.terminate();

    return 0;
}