#pragma once

#include "../util/WindowManager.h"

class Input
{
public:
	Input(WindowManager* wndMngr) : wndMngr(wndMngr) {

	}

	void init();
	void run();

private:
	WindowManager* wndMngr;
};