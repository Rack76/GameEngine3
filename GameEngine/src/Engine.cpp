#include "Engine.h"
#include "util/event/Events.h"
#include <string>

void Engine::init()
{
	//init librairies
	//instantiate systems
	//add entity types to systems
	//add entities
	bool* pshouldRun = &shouldRun;
	const std::function<void()> func = [pshouldRun]() {*pshouldRun = false; };
	EscPress::registerListener(func);
}

void Engine::run()
{
	//loop w exit condition
		//tasks update (Task Sheduler/Manager)

	while (shouldRun) //TODO exit condtion
	{
		taskManager.runTasks();

		//TODO updaterate controller -> Ticks time ?
	}
}
