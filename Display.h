#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Manage {
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void setCallbacks(GLFWwindow* window) {
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	}

	void processInput(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}

	

	// Validates initalization methods
	int checkInit() {
		// Load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD." << std::endl;
			return -1;
		}
	}
}

class Display
{
public:
	GLFWwindow * window;
	Display(int width = 1280, int height = 720, const char *title = "Display") {
		init();
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		checkInit(window);
		glfwMakeContextCurrent(window);
		Manage::setCallbacks(window);
		Manage::checkInit();
	}

private:
	void init() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glEnable(GL_DEPTH_TEST);
	}

	void checkInit(GLFWwindow* window) {
		if (window == NULL) {
			std::cout << "Failed to create GLFW window." << std::endl;
			glfwTerminate();
			return;
		}
	}
	
};

