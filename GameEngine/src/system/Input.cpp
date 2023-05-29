#include "Input.h"
#include "glfw3.h"
#include "../component/Camera.h"
#include "../util/math/Operator.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursorCallback(GLFWwindow* window, double xpos, double ypos);

void Input::init()
{
	ON_ESC_PRESS::registerListener([]() {TERMINATE::call(); });
	glfwSetKeyCallback(wndMngr->getWindow(), keyCallback);
	glfwSetCursorPosCallback(wndMngr->getWindow(), cursorCallback);
	glfwSetWindowUserPointer(wndMngr->getWindow(), this);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	auto input = (Input*)glfwGetWindowUserPointer(window);
	if (action == GLFW_PRESS)
	{
		switch (key) {
		case GLFW_KEY_ESCAPE:
		{
			ON_ESC_PRESS::call();
		}
		break;
		case GLFW_KEY_A:
		{
			if(glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
				input->translateCameraX(0.1);
		}
		break;
		case GLFW_KEY_D:
		{
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
				input->translateCameraX(-0.1);
		}
		break;
		case GLFW_KEY_W:
		{
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
				input->translateCameraZ(-0.1);
		}
		break;
		case GLFW_KEY_S:
		{
			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
				input->translateCameraZ(0.1);
		}
		break;
		case GLFW_KEY_LEFT_SHIFT:
		{
			if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
				input->translateCameraY(-0.1);
		}
		break;
		case GLFW_KEY_SPACE:
		{
			if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
				input->translateCameraY(0.1);
		}
		break;
		}

	}
	else if(action == GLFW_RELEASE)
	{
		switch (key) {
		case GLFW_KEY_A:
		{
			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
				input->translateCameraX(-0.1);
			else
				input->stopCameraX();
		}
		break;
		case GLFW_KEY_D:
		{
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
				input->translateCameraX(0.1);
			else
				input->stopCameraX();
		}
		break;
		case GLFW_KEY_S:
		{
			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
				input->translateCameraZ(-0.1);
			else
				input->stopCameraZ();
		}
		break;
		case GLFW_KEY_W:
		{
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
				input->translateCameraZ(0.1);
			else
				input->stopCameraZ();
		}
		break;
		case GLFW_KEY_LEFT_SHIFT:
		{
			if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
				input->translateCameraY(0.1);
			else
				input->stopCameraY();
		}
		break;
		case GLFW_KEY_SPACE:
		{
			if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				input->translateCameraY(-0.1);
			else
				input->stopCameraY();
		}
		break;
		}
	}
}


void cursorCallback(GLFWwindow* window, double xpos, double ypos)
{
	auto input = (Input*)glfwGetWindowUserPointer(window);
	input->rotateCamera(window, xpos, ypos);
}

void Input::translateCameraX(float x) {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->xVelocity = camera->orientation.rx * x;
}

void Input::translateCameraY(float y) {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->yVelocity = Math::Vec3(0.0f, 1.0f, 0.0f) * y;
}

void Input::translateCameraZ(float z) {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->zVelocity = Math::Vec3(camera->orientation.rz.x, 0.0f, camera->orientation.rz.z);
	camera->zVelocity.normalize();
	camera->zVelocity = camera->zVelocity * z;
}

void Input::stopCamera() {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->xVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
	camera->yVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
	camera->zVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
}

void Input::stopCameraX() {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->xVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
}

void Input::stopCameraY() {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->yVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
}

void Input::stopCameraZ() {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	camera->zVelocity = Math::Vec3(0.0f, 0.0f, 0.0f);
}

void Input::rotateCamera(GLFWwindow* window, double xDiff, double yDiff) {
	auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
	Math::Vec3 up = Math::Vec3(0.0f, 1.0f, 0.0f);
	static double xpos = 0;
	xpos += (xDiff - 500) / 1000.0f;
	static double ypos = 0;
	ypos += (yDiff - 380) / 1000.0f;
	if (ypos > radians(89))
		ypos = radians(89);

	if (ypos < -radians(89))
		ypos = -radians(89);
	Math::Vec3 orientation = Math::Vec3((float)cos(ypos) * (float)sin(xpos), (float)sin(ypos), (float)cos(xpos) * (float)cos(ypos));
	Math::Vec3 cameraLeft = Math::cross(up, orientation);
	cameraLeft.normalize();

	Math::Vec3 cameraY = Math::cross(cameraLeft, orientation);
	cameraY.normalize();
	camera->orientation.rx = cameraLeft;
	camera->orientation.ry = cameraY;
	camera->orientation.rz = orientation;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		translateCameraX(0.1);
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		translateCameraX(-0.1);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		translateCameraY(0.1);
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		translateCameraY(-0.1);
	if (glfwGetKey(window, GLFW_KEY_W == GLFW_PRESS))
		translateCameraZ(-0.1);
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		translateCameraZ(0.1);
}

void Input::run()
{
	glfwPollEvents();
	glfwSetCursorPos(wndMngr->getWindow(), 500, 380);
}
