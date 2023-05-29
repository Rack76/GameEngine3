#pragma once

#include "../component/Camera.h"
#include "../util/event/Events.h"
#include "../component/Model3D.h"
#include "../util/WindowManager.h"
#include "EntityManager.h"

class Renderer
{
public:
	Renderer(WindowManager* wndMngr,
		EntityManager* ettMngr) : wndMngr(wndMngr) , ettMngr(ettMngr) {

	}

	void loadVertices(int entityType, int index);
	void storeProgram(int vertexShaderName, int fragmentShaderName,
		std::string vertexShaderFileName, std::string fragmentShaderFileName);
	void storeVerticeData(std::string filename, std::vector<GLfloat> orderedVertices, std::vector<GLfloat> orderedTextCoord);
	void assignProgram(int entityType, int index);
	void init();
	void run();

private:
	std::map<std::string, std::map<std::string, GLuint>> programs;
	std::map<std::string, std::vector<GLfloat>> modelsVertices;
	std::map<std::string, std::vector<GLfloat>> modelsTextCoord;
	WindowManager* wndMngr;
	EntityManager* ettMngr;
};