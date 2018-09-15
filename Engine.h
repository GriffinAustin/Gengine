#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Display.h"

class Engine {
public:
	GLFWwindow* window;
	Engine(GLFWwindow* nWindow) {
		window = nWindow;
	}
	
	int loop(GLFWwindow* window) {
		while (!glfwWindowShouldClose(window)) {
			Manage::processInput(window);

			// Background color
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
};