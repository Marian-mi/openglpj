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
//		window = glfwCreateWindow(940, 640, "Fuck the World", NULL, NULL);
//		if (!window)
//		{
//			glfwTerminate();
//			return -1;
//		}
//
//		glfwMakeContextCurrent(window);
//
//		if (glewInit() != GLEW_OK)
//			std::cout << "motherfucker GLEW failed!";
//
//		std::cout << glGetString(GL_VERSION);
//
//		float productofshit = sqrt(pow(600, 2) - pow(300, 2));
//		float vertices[] = {
//			   100.0f,  100.0f,  
//			   700.0f,  100.0f,  
//			   400.0f,  productofshit,  
//			   250.0f, (productofshit + 100) / 2,
//			   550.0f, (productofshit + 100) / 2,
//			   400.0f, 100.0f,
//		};
//		
//		uint32_t indBuffer[] = {
//			0, 1, 2,
//			3, 4, 5,
//		};
//
//		GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
//		GLCALL(glEnable(GL_BLEND));
//
//		//Texture texture("res/img/counts-bg.jpg");
//		//texture.Bind();
//
//		VertexBuffer vbo = VertexBuffer(vertices, 4 * 4 * sizeof(float));
//
//		VertexBufferLayout vblo;
//		vblo.Push<float>(2);
//
//		VertexArray vao = VertexArray(vbo, vblo);
//
//		IndexBuffer ibo(indBuffer, 6);
//
//		std::string filepath = "res/shaders/Basic.Shader";
//		Shader shader(filepath);
//		shader.Bind();
//
//
//		glm::mat4 proj = glm::ortho(0.0f, 940.0f, 0.0f, 640.0f, -1.0f, 100.0f);
//		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
//
//		std::string uniform1Name = "u_Color";
//		shader.SetUniform4f(uniform1Name, 1.0f, 0.0f, 0.5f, 1.0f);
//
//		//std::string uniformName2 = "u_Texture";
//		//shader.SetUniform1i(uniformName2, 0);
//
//		shader.UnBind();
//		vao.UnBind();
//		vbo.UnBind();
//		vao.UnBind();
//
//		Renderer renderer;
//
//		//ImGui::CreateContext();
//		//ImGui_ImplGlfwGL3_Init(window, true);
//		//ImGui::StyleColorsDark();
//
//		glm::vec3 translation0(0, 0, 0);
//		glm::vec3 translation1(400, 200, 0);
//
//		while (!glfwWindowShouldClose(window))
//		{
//			renderer.Clear();
//
//			//ImGui_ImplGlfwGL3_NewFrame();
//
//			std::string uniform1Name1 = "u_MVP";
//
//			{
//				glm::mat4 model = glm::translate(glm::mat4(1.0f), translation0);
//				glm::mat4 mvp = proj * view * model;
//				shader.Bind();
//				shader.SetUniformMat4f(uniform1Name1, mvp);
//
//				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//				renderer.Draw(vao, ibo, shader);
//			}
//
//			/*{
//				glm::mat4 model = glm::translate(glm::mat4(1.0f), translation1);
//				glm::mat4 mvp = proj * view * model;
//				shader.SetUniformMat4f(uniform1Name1, mvp);
//				shader.Bind();
//
//				renderer.Draw(vao, ibo, shader);
//			}*/
//			
//			//{       
//			//	ImGui::SliderFloat3("Translation0", &translation0.x, 0.0f, 960.0f);
//			//	ImGui::SliderFloat3("Translation1", &translation1.x, 0.0f, 960.0f);
//			//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//			//}
//			//
//			//ImGui::Render();
//			//ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
//
//			
//
//			glfwSwapBuffers(window);
//
//			glfwPollEvents();
//		}
//
//
//	}
//
//	//ImGui_ImplGlfwGL3_Shutdown();
//	//ImGui::DestroyContext();
//	glfwTerminate();
//
//	return 0;
//}