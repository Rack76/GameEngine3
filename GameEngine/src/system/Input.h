#pragma once

#include "../util/event/Events.h"
#include "../util/WindowManager.h"
#include "EntityManager.h"

class Input
{
public:
	Input(WindowManager* wndMngr, EntityManager* ettMngr) : wndMngr(wndMngr), ettMngr(ettMngr) {

	}

	void init();
	void rotateCamera(GLFWwindow*, double xpos, double ypos);
	void translateCameraX(float);
	void translateCameraY(float);
	void translateCameraZ(float);
	void stopCameraX();
	void stopCameraY();
	void stopCameraZ();
	void stopCamera();
	void run();

private:
	WindowManager* wndMngr;
	EntityManager* ettMngr;
};