#pragma once

#include "system/System.h"
#include "TaskManager.h"
#include <vector>

class Engine
{
public:
	void init();
	void run();

private:
	std::vector<System> systems;
	TaskManager taskManager;
};