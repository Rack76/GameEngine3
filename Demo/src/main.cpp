#include "../../GameEngine/src/Engine.h"
#include <cassert>

int main(void)
{
    Engine engine;
    engine.init();
    engine.ettMngr->addEntityType(0, 0, 1);
    engine.ettMngr->addEntityType(1, 0);
    engine.ettMngr->addEntity(0);
    engine.ettMngr->addEntity(1);
    engine.ettMngr->serialize_ss();
    //engine.run();

    engine.terminate();
    //engine.terminate();

    return 0;
}