#pragma once
#include "glew.h"
#include <cmath>
#include <memory>

namespace Math
{
	void makePerspective(GLfloat perspective[16], float near, float far, float FOV, float aspectRatio);
}