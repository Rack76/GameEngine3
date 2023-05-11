#include "WindowManager.h"
#include "glfw3.h"

void WindowManager::CreateWindow()
{
	wnd = glfwCreateWindow(1000, 760, "Window", nullptr, nullptr);
}

GLFWwindow* WindowManager::getWindow()
{
	return wnd;
}
