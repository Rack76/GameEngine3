#pragma once

class Engine;

class GameMode
{
public:
	virtual void load() = 0;

protected:
	Engine* engine;
};