/*
 * InputManager.h
 *
 *  Created on: 21 Dec 2013
 *      Author: bert
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library

#include "../Util/Logger.h"
#include "openglmanager.h"

#define NOKEY -1 //for GLFW to indicate the key was not pressed

namespace OpenGL {

class InputManager {
public:
	InputManager();
	virtual ~InputManager();

    void Init(OpenGLManager* opengl);

	void PollEvents();

	bool IsEscapePressed();
	bool IsLeftPressed();
	bool IsRightPressed();
	bool IsUpPressed();
	bool IsDownPressed();
	bool IsAPressed();
	bool IsSPressed();
	bool IsDPressed();
	bool IsPPressed();
	bool IsXPressed();
	bool IsYPressed();
	bool IsCPressed();
	bool IsSpacebarPressed();

	void RegisterOnMouseButton(void (*onMouseButton)(int button, int action, int mods));
	void RegisterOnMouseMove(void (*onMouseMove)(double x, double y));

private:
	OpenGLManager* opengl;
	bool isEscapePressed;
	bool isLeftPressed;
	bool isRightPressed;
	bool isUpPressed;
	bool isDownPressed;
	log4cpp::Category* logger;
    int pressedKeys[GLFW_KEY_LAST];

	void (*reg_onMouseButton)(int button, int action, int mods);
	void (*reg_onMouseMove)(double x, double y);

	void onKey(int key, int action, int mods);
	void onMouseButton(int button, int action, int mods);
	void onMouseMove(double x, double y);
	void onMouseWheel(double xoffset, double yoffset);
    bool ToggleKey(int key, bool isCheckRelease=true, bool isCheckPress=true);

	static void glfw_onKey(GLFWwindow *window, int key, int scancode, int action, int mods) {
		manager->onKey(key, action, mods);
	}

	static void glfw_onMouseButton(GLFWwindow *window, int button, int action, int mods) {
		manager->onMouseButton(button, action, mods);
	}

	static void glfw_onMouseMove(GLFWwindow *window, double x, double y) {
		manager->onMouseMove(x, y);
	}

	static void glfw_onMouseWheel(GLFWwindow *window, double xoffset, double yoffset) {
		manager->onMouseWheel(xoffset, yoffset);
	}

	static InputManager* manager;
};

}

#endif /* INPUTMANAGER_H_ */
