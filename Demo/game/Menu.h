#pragma once
#include "../../GameEngine/src/game/GameMode.h"
class Engine;

class MainMenu : public GameMode
{
public:
	MainMenu(Engine* engine) : engine(engine) {

	}
	virtual void load();

private:
	Engine* engine;
};