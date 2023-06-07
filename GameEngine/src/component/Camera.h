#pragma once
#include "glew.h"
#include "Component.h"
#include "../util/math/Mat4.h"
#include "../util/math/Mat3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory>
#define radians(degrees) ((degrees/ 180.0f) * M_PI)

class Camera : public IComponent
{
public:
	Camera()
		{
		float near = 1.0f;
		float far = 50.0f;
		float FOV = radians(20);
		float aspectRatio = 760.0f/ 1000.0f;
		float width = 2 * near * tan(FOV / 2);
		float height = aspectRatio * width;

		perspective[0] = near / (width / 2);
		perspective[1] = 0;
		perspective[2] = 0;
		perspective[3] = 0;
		perspective[4] = 0;
		perspective[5] = near / (height / 2);
		perspective[6] = 0;
		perspective[7] = 0;
		perspective[8] = 0;
		perspective[9] = 0;
		perspective[10] = (near + far) / (far - near);
		perspective[11] = (2 * far * near) / (near - far);
		perspective[12] = 0;
		perspective[13] = 0;
		perspective[14] = 1;
		perspective[15] = 0;
	}
	virtual void deserialize(std::vector<std::string>) {

	}
	virtual void serialize(std::ofstream&) {

	}
	virtual void serialize(std::ostringstream&) {

	}


	GLfloat perspective[16];
	Math::Mat3<GLfloat> orientation = Math::Mat3<GLfloat>(Math::Vec3<GLfloat>(1.0f, 0.0f, 0.0f),
		Math::Vec3<GLfloat>(0.0f, 1.0f, 0.0f),
		Math::Vec3<GLfloat>(0.0f, 0.0f, 1.0f));
	Math::Vec3<GLfloat> position = Math::Vec3(0.0f, 0.0f, 20.0f);
	Math::Vec3<GLfloat> xVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
	Math::Vec3<GLfloat> yVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
	Math::Vec3<GLfloat> zVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
};
