#pragma once
#include "Component.h"
#include "glew.h"

class Shader : public Component
{
public:
	Shader() : vertexShadername("basic.vert") ,
		fragmentShadername("basic.frag") {

	}

	virtual void deserialize(std::vector<std::string>) {

	}
	virtual void serialize(std::ofstream&) {

	}
	virtual void serialize(std::ostringstream&) {

	}

	~Shader() {
		glDeleteProgram(program);
	}

	std::string vertexShadername;
	std::string fragmentShadername;
	GLuint program;
};