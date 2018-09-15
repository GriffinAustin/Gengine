// Graphical
#include <glad/glad.h>
#include <glad/glad.c>
#include <GLFW/glfw3.h>

// Default headers
#include <iostream>

// Classes
#include "Display.h"
#include "Engine.h"

int main() {
	Display display(800, 600, "Gengine");
	Engine engine(display.window);

	engine.loop(display.window);

	return 0;
}