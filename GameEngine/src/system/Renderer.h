#pragma once

#include "../util/WindowManager.h"

class Renderer
{
public:
	Renderer(WindowManager* wndMngr) : wndMngr(wndMngr) {

	}

	void init();
	void run();

private:
	WindowManager* wndMngr;
};