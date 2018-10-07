#pragma once
#ifndef LOADER_H
#define LOADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>



unsigned int loadToVAO() {
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	return VAO;
}

unsigned int loadToVBO() {
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	return VBO;
}

void loadAttributes(int index, int size, GLsizei stride, const void *pointer) {
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(index);
}
#endif