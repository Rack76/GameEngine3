#pragma once

#include <map>
#include <memory>
#include <exception>
#include <iostream>
#include "GameMode.h"
class Engine;

class Game
{
public:
	void init(Engine* engine); // define your game modes, insert them in map, and define your current game mode

	void loadFirstGameMode() {
		(*firstGameMode.get())->load();
	}

	void loadGameMode(int gameMode) {
		try {
			(*gameModes.at(gameMode).get())->load();
		}
		catch (std::exception& e) {
			std::cerr << e.what();
		}
	}

private:

	std::map<int, std::unique_ptr<GameMode*>> gameModes;
	std::unique_ptr<GameMode*> firstGameMode;
	Engine* engine;
};