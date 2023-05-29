#pragma once

#include "glew.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "../system/EntityManager.h"

class Parser {
public:
	Parser(EntityManager* ettMnger) : ettMnger(ettMnger) {

	}

	void parseShader(std::string vertexShaderfileName, std::string fragmentShaderfileName);
	void deserialize(std::string filename);
	void deserialize_ss(std::stringstream&);
	void parseCollada(std::string);
	
private:
	void loadShaderSource(std::string shaderfileName, GLuint program);
	EntityManager* ettMnger;
};