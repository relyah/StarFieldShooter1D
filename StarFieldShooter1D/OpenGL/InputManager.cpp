/*
 * InputManager.cpp
 *
 *  Created on: 21 Dec 2013
 *      Author: bert
 */

#include "InputManager.h"

OpenGL::InputManager* OpenGL::InputManager::manager = 0;

namespace OpenGL {

InputManager::InputManager() {
	opengl = 0;
	isEscapePressed = false;
	isUpPressed = false;
	isDownPressed = false;
	isLeftPressed = false;
	isRightPressed = false;

	reg_onMouseButton = 0;
	reg_onMouseMove = 0;

    logger = Util::Logger::GetLogger();

	for (int i = 0; i < GLFW_KEY_LAST; i++) {
        pressedKeys[i] = NOKEY;
	}
}

InputManager::~InputManager() {
    logger->info("Input manager shutting down...");
	opengl = 0;
    logger->info("Input manager shutdown.");
	logger = 0;
}

void InputManager::Init(OpenGLManager* opengl) {
    logger->info("Input manager starting...");
    InputManager::manager = this;

	this->opengl = opengl;

	glfwSetKeyCallback(opengl->GetWindow(), glfw_onKey);
	glfwSetMouseButtonCallback(opengl->GetWindow(), glfw_onMouseButton);
	glfwSetCursorPosCallback(opengl->GetWindow(), glfw_onMouseMove);
	glfwSetScrollCallback(opengl->GetWindow(), glfw_onMouseWheel);

    logger->info("Input manager started.");
}

void InputManager::PollEvents() {
	glfwPollEvents();
}

bool InputManager::IsEscapePressed() {
	return ToggleKey(GLFW_KEY_ESCAPE);
}

bool InputManager::IsLeftPressed() {
	return ToggleKey(GLFW_KEY_LEFT);
}
bool InputManager::IsRightPressed() {
	return ToggleKey(GLFW_KEY_RIGHT);
}
bool InputManager::IsUpPressed() {
	return ToggleKey(GLFW_KEY_UP);
}
bool InputManager::IsDownPressed() {
	return ToggleKey(GLFW_KEY_DOWN);
}
bool InputManager::IsAPressed() {
	return ToggleKey(GLFW_KEY_A);
}
bool InputManager::IsSPressed() {
	return ToggleKey(GLFW_KEY_S);
}
bool InputManager::IsDPressed() {
	return ToggleKey(GLFW_KEY_D);
}
bool InputManager::IsPPressed() {
	return ToggleKey(GLFW_KEY_P);
}
bool InputManager::IsXPressed() {
	return ToggleKey(GLFW_KEY_X);
}
bool InputManager::IsYPressed() {
	return ToggleKey(GLFW_KEY_Y);
}
bool InputManager::IsCPressed() {
	return ToggleKey(GLFW_KEY_C);
}
bool InputManager::IsSpacebarPressed() {
    return ToggleKey(GLFW_KEY_SPACE,false,true);
}

bool InputManager::ToggleKey(int key, bool isCheckRelease, bool isCheckPress) {
    bool result = (isCheckRelease && pressedKeys[key]==GLFW_RELEASE) || ( isCheckPress && pressedKeys[key]==GLFW_PRESS);
    pressedKeys[key] = NOKEY;
	return result;
}

void InputManager::RegisterOnMouseButton(void (*reg_onMouseButton)(int button, int action, int mods)) {
	this->reg_onMouseButton = reg_onMouseButton;
}

void InputManager::RegisterOnMouseMove(void (*reg_onMouseMove)(double x, double y)) {
	this->reg_onMouseMove = reg_onMouseMove;
}

void InputManager::onKey(int key, int action, int mods) {

    //std::stringstream sstm;
    //sstm << "Key: " << key << " Action:" << action;
    //logger->debug(sstm.str());

    pressedKeys[key] = action;
}

void InputManager::onMouseButton(int button, int action, int mods) {
	if (reg_onMouseButton != 0) {
		reg_onMouseButton(button, action, mods);
	}
}

void InputManager::onMouseMove(double x, double y) {
	if (reg_onMouseMove != 0) {
		reg_onMouseMove(x, y);
	}
}

void InputManager::onMouseWheel(double xoffset, double yoffset) {

}

}
