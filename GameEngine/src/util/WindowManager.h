#pragma once
#include <string>

class GLFWwindow;

class WindowManager 
{
public:
	void CreateWindow();
	GLFWwindow* getWindow();

private:
	GLFWwindow* wnd;
};