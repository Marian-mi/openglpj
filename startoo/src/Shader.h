#pragma once

#include <string>
#include "vendors/GLM/glm.hpp"

struct Vec4 {
	float f1;
	float f2;
	float f3;
	float f4;
};

struct ProgramShadersResources
{
	std::string VertexResource;
	std::string FragmentResource;
};

class Shader {
private:
	std::string m_Filepath;
	unsigned int m_RendererId;
public:
	Shader(std::string& filepath);
	~Shader();

	void Bind() const;
	void UnBind() const;

	void SetUniform4f(std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(std::string& name, int i0);
	void SetUniformMat4f(std::string& name, glm::mat4& matrix);
private:
	ProgramShadersResources ParseShaders(std::string& filepath);
	int GetUniformLocation(const std::string& name);
	unsigned int ComplieShader(uint32_t type, std::string& source);
	uint32_t CreateShader(std::string& vertexShader, std::string& fragmentShader);
};