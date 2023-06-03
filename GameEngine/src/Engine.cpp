#include <cassert>
#include "Engine.h"
#include "util/event/Events.h"
#include <string>
#include "glfw3.h"
#include "util/WindowManager.h"
#include "game/Game.h"

void Engine::init(Game* game)
{
	//init librairies
	if (!glfwInit())
		assert(0 && "error : could not load glfw");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

	wndMngr = new WindowManager();
	ettMngr = new EntityManager();
	input = new Input(wndMngr, ettMngr);
	renderer = new Renderer(wndMngr, ettMngr);
	taskManager = new TaskManager();
	serializator = new Serializator(ettMngr);
	parser = new Parser(ettMngr);

	renderer->init();
	input->init();
	ettMngr->init();
	serializator->init();
	bool* pshouldRun = &shouldRun;
	const std::function<void()> func = [pshouldRun]() {*pshouldRun = false; };
	TERMINATE::registerListener("terminate", func);

	glfwSetCursorPos(wndMngr->getWindow(), 500, 380);

	game->loadFirstGameMode();
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
	delete wndMngr;
	delete ettMngr;
	delete input;
	delete renderer;
	delete taskManager;
	delete serializator;
	delete parser;
	glfwTerminate();
}
