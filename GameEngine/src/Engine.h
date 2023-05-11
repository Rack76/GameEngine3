#pragma once

#include "system/Input.h"
#include "system/Renderer.h"
#include "system/EntityManager.h"
#include "System/Serializator.h"
#include "util/TaskManager.h"
#include <vector>

class Engine
{
public:
	Engine() {

	}

	void init();
	void run();
	void terminate();

private:
	EntityManager* ettMngr;
	Input* input;
	Renderer* renderer;
	Serializator* serializator;
	TaskManager* taskManager;
	WindowManager* wndMngr;
	bool shouldRun = true;
	
};