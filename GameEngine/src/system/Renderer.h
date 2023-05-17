#pragma once

#include "../component/Model3D.h"
#include "../util/WindowManager.h"
#include "EntityManager.h"

class Renderer
{
public:
	Renderer(WindowManager* wndMngr,
		EntityManager* ettMngr) : wndMngr(wndMngr) , ettMngr(ettMngr) {

	}

	void specifyVertices(int entityType, int index);
	void init();
	void run();

private:
	WindowManager* wndMngr;
	EntityManager* ettMngr;
};