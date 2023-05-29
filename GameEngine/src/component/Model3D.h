#pragma once
#include "Component.h"
#include "glew.h"

enum {VERTICES, TEXTURE};

class Model3D :public Component
{
public:
	Model3D() {
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

	int vertexCount;
	std::string filename;
	GLuint vao;
	GLuint vbo[2];
};