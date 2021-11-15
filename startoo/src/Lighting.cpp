#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "mesh/Cube.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"

#include "GLFW/glfw3.h"
#include "GL/glew.h"
#include "vendors/GLM/glm.hpp"

#include <iostream>

auto cameraPos = glm::vec3(0.0f, 0.0f, 2.0f);
auto cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
auto cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

int main(void) {
	{
		GLFWwindow* window;

		if (!glfwInit())
			return -1;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(620, 960, "Fuck world", NULL, NULL);
		if (!window) {
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			std::cout << "GLEW initialization failed!\n";
		}

		std::string lightingShaderFilepath = "/res/shaders/LightingTarget.Shader";
		Shader lighitngShader(lightingShaderFilepath);

		VertexBuffer target1VBO(cuveVerticesRaw, 84 * sizeof(float));

		float indexBuffer[36];
		for (size_t i = 0; i < 36; i++)
		{
			indexBuffer[i] = i;
		}
		IndexBuffer IBO(indexBuffer, 36);

		VertexBufferLayout target1VBLO;
		target1VBLO.Push<float>(3);

		VertexArray target1VAO(target1VBO, target1VBLO);

		std::string lightingShaderFilepath = "/res/shaders/LightingSource.Shader";
		Shader sourceShader(lightingShaderFilepath);

		VertexBuffer sourceVBO(cuveVerticesRaw, 84 * sizeof(float));

		VertexBufferLayout target1VBLO;
		target1VBLO.Push<float>(3);

		VertexArray sourceVAO(target1VBO, target1VBLO);

		Renderer renderer;

		while (!glfwWindowShouldClose(window)) {
			renderer.Clear();

			{

			}

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}