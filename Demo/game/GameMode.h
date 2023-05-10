#pragma once

class Engine;

class GameMode
{
public:
	GameMode(Engine* engine) : engine(engine) {}
	virtual void load() = 0;

protected:
	Engine* engine;
};