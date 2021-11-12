#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

#include "vendors/GLM/glm.hpp"
#include "vendors/GLM/gtc/matrix_transform.hpp"
#include "vendors/stb_image/stb_image.h"

int main(void)
{
	{
		GLFWwindow* window;

		if (!glfwInit())
			return -1;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(940, 480, "Fuck the World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			std::cout << "motherfucker GLEW failed!";

		std::cout << glGetString(GL_VERSION);

		float vertices[] = {
			  200.0f,  100.0f,  0.0f,  0.0f,
			  400.0f,  100.0f,  1.0f,  0.0f,
			  400.0f,  300.0f,  1.0f,  1.0f,
			  200.0f,  300.0f,  0.0f,  1.0f,
		};

		uint32_t indBuffer[] = {
			0, 1, 2,
			2, 3, 0,
		};

		GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCALL(glEnable(GL_BLEND));

		Texture texture("res/img/counts-bg.jpg");
		texture.Bind();

		VertexBuffer vbo = VertexBuffer(vertices, 4 * 4 * sizeof(float));

		VertexBufferLayout vblo;
		vblo.Push<float>(2);
		vblo.Push<float>(2);

		VertexArray vao = VertexArray(vbo, vblo);

		IndexBuffer ibo(indBuffer, 6);

		std::string filepath = "res/shaders/Basic.Shader";
		Shader shader(filepath);
		shader.Bind();


		glm::mat4 proj = glm::ortho(0.0f, 940.0f, 0.0f, 480.0f, -1.0f, 100.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 0.0f, 0.0f));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(100.0f, 100.0f, -0.0f));

		glm::mat4 mvp = proj * view * model;

		std::string uniform1Name = "u_Color";
		shader.SetUniform4f(uniform1Name, 1.0f, 0.0f, 0.5f, 1.0f);

		std::string uniform1Name1 = "u_MVP";
		shader.SetUniformMat4f(uniform1Name1, mvp);

		std::string uniformName2 = "u_Texture";
		shader.SetUniform1i(uniformName2, 0);

		shader.UnBind();
		vao.UnBind();
		vbo.UnBind();
		vao.UnBind();

		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();

			vao.Bind();
			renderer.Draw(vao, ibo, shader);

			glfwSwapBuffers(window);

			glfwPollEvents();
		}


	}

	glfwTerminate();
	return 0;
}