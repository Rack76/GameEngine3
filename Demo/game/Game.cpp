#include "../../GameEngine/src/game/Game.h"
#include "Menu.h"

enum {MAIN_MENU};

void Game::init(Engine *engine) {
	this->engine = engine;
	gameModes.insert(std::pair<int, std::shared_ptr<GameMode>>(MAIN_MENU, new MainMenu(engine)));
	firstGameMode = gameModes[MAIN_MENU];
}