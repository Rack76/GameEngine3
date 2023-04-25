#include "Engine.h"

void Engine::init()
{
	//init librairies
	//instantiate systems
	//add entity types to systems
	buildArchetypes(systems);
}

void Engine::run()
{
	//loop w exit condition
		//tasks update (Task Sheduler/Manager)

	while (true) //TODO exit condtion
	{
		updateTasks();
	}
}
