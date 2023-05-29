#include "../../GameEngine/src/Engine.h"
#include <cassert>
#include "../../GameEngine/src/game/Game.h"

int main(void)
{
    Game game;
    Engine engine;
    game.init(&engine);
    engine.init(&game);
    engine.run();

    engine.terminate();
    //engine.terminate();

    return 0;
}