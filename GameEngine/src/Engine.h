#pragma once

#include "system/Input.h"
#include "system/Renderer.h"
#include "system/EntityManager.h"
#include "System/Serializator.h"
#include "util/TaskManager.h"
#include "util/Parser.h"
#include <vector>

class Engine
{
public:
	Engine() {

	}

	void init();
	void run();
	void terminate();

	EntityManager* ettMngr;
	WindowManager* wndMngr;
	Parser* parser;

private:
	Input* input;
	Renderer* renderer;
	Serializator* serializator;
	TaskManager* taskManager;
	bool shouldRun = true;
	
};