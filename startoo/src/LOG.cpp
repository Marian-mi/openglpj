//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <math.h>
//
//#include "Renderer.h"
//#include "VertexBuffer.h"
//#include "IndexBuffer.h"
//#include "VertexArray.h"
//#include "VertexBufferLayout.h"
//#include "Shader.h"
//#include "Texture.h"
//
//#include "vendors/GLM/glm.hpp"
//#include "vendors/GLM/gtc/matrix_transform.hpp"
//#include "vendors/stb_image/stb_image.h"
//
//#include "vendors/IMGUI/imgui.h"
//#include "vendors/IMGUI/imgui_impl_glfw_gl3.h"
//
//#include "mesh/Cube.h"
//
//void processInput(GLFWwindow* window);
//void mouserMovementCallback(GLFWwindow* window, double xPos, double yPos);
//
//struct lastMousePos {
//	double lastX = 400.0f, lastY = 300.0f;
//};
//lastMousePos* lastmousepos = new lastMousePos;
//
//
//bool isFirstMove = true;
//
//float yaw = -90.0f;
//float pitch = 0.0f;
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//float deltaTime = 0.0f;
//float lastFrameTime = 0.0f;
//
//int main(void)
//{
//	{
//		GLFWwindow* window;
//
//		if (!glfwInit())
//			return -1;
//
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//		window = glfwCreateWindow(800, 600, "Fuck the World", NULL, NULL);
//		if (!window)
//		{
//			glfwTerminate();
//			return -1;
//		}
//
//		glfwMakeContextCurrent(window);
//
//		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//		glfwSetCursorPosCallback(window, mouserMovementCallback);
//
//
//		if (glewInit() != GLEW_OK)
//			std::cout << "motherfucker GLEW failed!";
//
//		std::cout << glGetString(GL_VERSION);
//		float vertices[] = {
//			   -1.0f,  -1.0f,
//			   1.0f,  -1.0f,
//			   0.0f,  1.0f,
//		};
//
//		uint32_t indBuffer[36];
//
//		for (int i = 0; i < 36; i++) {
//			indBuffer[i] = i;
//		}
//
//		GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
//		GLCALL(glEnable(GL_BLEND));
//		glEnable(GL_DEPTH_TEST);
//
//
//		Texture texture("res/img/container.jpg");
//		texture.Bind();
//
//		VertexBuffer vbo = VertexBuffer(cuveVertices, 180 * sizeof(float));
//
//		VertexBufferLayout vblo;
//		vblo.Push<float>(3);
//		vblo.Push<float>(2);
//
//		VertexArray vao = VertexArray(vbo, vblo);
//
//		IndexBuffer ibo(indBuffer, 36);
//
//		std::string filepath = "res/shaders/Basic.Shader";
//		Shader shader(filepath);
//		shader.Bind();
//
//		glm::mat4 view = glm::mat4(1.0f);
//
//		glm::mat4 model = glm::mat4(1.0f);
//
//		std::string uniform1Name = "u_Color";
//		shader.SetUniform4f(uniform1Name, 1.0f, 0.0f, 0.5f, 1.0f);
//
//		glm::mat4 projection;
//		projection = glm::perspective(glm::radians(90.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//
//
//		std::string textureUniformName = "u_Texture";
//		shader.SetUniform1i(textureUniformName, 0);
//
//
//		shader.UnBind();
//		vao.UnBind();
//		vbo.UnBind();
//		vao.UnBind();
//
//		glm::vec3 cubePositions[] = {
//			glm::vec3(0.0f,  0.0f,  0.0f),
//			glm::vec3(2.0f,  5.0f, -15.0f),
//			glm::vec3(-1.5f, -2.2f, -2.5f),
//			glm::vec3(-3.8f, -2.0f, -12.3f),
//			glm::vec3(2.4f, -0.4f, -3.5f),
//			glm::vec3(-1.7f,  3.0f, -7.5f),
//			glm::vec3(1.3f, -2.0f, -2.5f),
//			glm::vec3(1.5f,  2.0f, -2.5f),
//			glm::vec3(1.5f,  0.2f, -1.5f),
//			glm::vec3(-1.3f,  1.0f, -1.5f)
//		};
//
//		Renderer renderer;
//
//		while (!glfwWindowShouldClose(window))
//		{
//			float currentFame = glfwGetTime();
//			deltaTime = currentFame - lastFrameTime;
//			lastFrameTime = currentFame;
//
//			renderer.Clear();
//
//			processInput(window);
//
//			view = glm::lookAt(cameraPos, cameraFront + cameraPos, cameraUp);
//
//
//			for (unsigned int i = 0; i < 10; i++)
//			{
//				glm::mat4 model = glm::mat4(1.0f);
//				model = glm::translate(model, cubePositions[i]);
//				float angle = 20.0f * i;
//				model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//
//
//				shader.Bind();
//				glm::mat4 mvp = projection * view * model;
//				std::string uniform1Name0 = "u_MVP";
//				shader.SetUniformMat4f(uniform1Name0, mvp);
//
//				renderer.Draw(vao, ibo, shader);
//
//			}
//
//
//			glfwSwapBuffers(window);
//
//			glfwPollEvents();
//		}
//
//
//	}
//	delete lastmousepos;
//	glfwTerminate();
//
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	const float cameraSpeed = 4.0f * deltaTime;
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		cameraPos += cameraSpeed * cameraFront;
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		cameraPos -= cameraSpeed * cameraFront;
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
//		cameraPos += cameraUp * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
//		cameraPos -= cameraUp * cameraSpeed;
//}
//
//void mouserMovementCallback(GLFWwindow* window, double xPos, double yPos) {
//	if (isFirstMove)
//	{
//		std::cout << "first" << std::endl;
//		lastmousepos->lastX = xPos;
//		lastmousepos->lastY = yPos;
//		isFirstMove = false;
//	}
//
//	double xoffset = xPos - lastmousepos->lastX;
//	double yoffset = lastmousepos->lastY - yPos; 
//	lastmousepos->lastX = xPos;
//	lastmousepos->lastY = yPos;
//
//	float sensitivity = 0.5f; // change this value to your liking
//	xoffset *= sensitivity;
//	yoffset *= sensitivity;
//
//	//std::cout << "x is: " << xoffset << std::endl;
//	//std::cout << "y is: " << yoffset << std::endl;
//
//
//	yaw += xoffset;
//	pitch += yoffset;
//	if (pitch > 89.0f)
//		pitch = 89.0f;
//	if (pitch < -89.0f)
//		pitch = -89.0f;
//
//	glm::vec3 direction;
//	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//	direction.y = sin(glm::radians(pitch));
//	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//	cameraFront = glm::normalize(direction);
//}