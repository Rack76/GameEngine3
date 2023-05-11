#include <cassert>
#include "Engine.h"
#include "util/event/Events.h"
#include <string>
#include "glfw3.h"
#include "util/WindowManager.h"

void Engine::init()
{
	//init librairies
	if (!glfwInit())
		assert(0 && "error : could not load glfw");

	wndMngr = new WindowManager();
	renderer = new Renderer(wndMngr);
	input = new Input(wndMngr);
	ettMngr = new EntityManager();
	taskManager = new TaskManager();
	serializator = new Serializator(ettMngr);

	renderer->init();
	input->init();
	ettMngr->init();
	serializator->init();
	bool* pshouldRun = &shouldRun;
	const std::function<void()> func = [pshouldRun]() {*pshouldRun = false; };
	TERMINATE::registerListener(func);
}

void Engine::run()
{
	//loop w exit condition
		//tasks update (Task Sheduler/Manager)

	while (shouldRun) //TODO exit condtion
	{
		taskManager->runTasks();
		renderer->run();
		input->run();
		//TODO updaterate controller -> Ticks time ?
	}
}

void Engine::terminate() {
	glfwTerminate();
}
