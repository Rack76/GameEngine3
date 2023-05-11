#include "Input.h"
#include "glfw3.h"
#include "../util/event/Events.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void Input::init()
{
	ON_ESC_PRESS::registerListener([]() {TERMINATE::call(); });
	glfwSetKeyCallback(wndMngr->getWindow(), keyCallback);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	switch(key) {
	case GLFW_KEY_ESCAPE:
		ON_ESC_PRESS::call();
	}
}

void Input::run()
{
	glfwPollEvents();
}
