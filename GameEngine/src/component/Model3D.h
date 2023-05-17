#pragma once
#include "Component.h"
#include "glew.h"

enum {VERTICES};

class Model3D :public Component
{
public:
	Model3D() {
		vertices = { -1.0f , 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f };
	}
	virtual void deserialize(std::vector<std::string>) {

	}
	virtual void serialize(std::ofstream&) {

	}
	virtual void serialize(std::ostringstream&) {

	}

	~Model3D() {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo[VERTICES]);
	}

	std::vector<GLfloat> vertices;
	GLuint vao;
	GLuint vbo[1];
};