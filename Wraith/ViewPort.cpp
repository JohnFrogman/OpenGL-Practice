#include "ViewPort.hpp"
#include <GL\glew.h>
#include <GLFW\glfw3.h>

ViewPort::ViewPort(int x, int y, DebugLog* aLog)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	//	printf("Hello world!");
	// --------------------------------------------------------------
	GLfloat verticies[] = {
		-0.5f	,-0.5f	,0.0f
		,0.5f	,-0.5f	,0.0f
		,0.0f	,0.5f	,0.0f
	};
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// --------------------------------------------------------------

	GLFWwindow* window = glfwCreateWindow(x, y, "Baby's First OpenGL Window", nullptr, nullptr);
	if (window == nullptr)
	{
		aLog->LogInfo("Failed to create GLFW window");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glViewport(0, 0, x, y);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
}


ViewPort::~ViewPort()
{
}
